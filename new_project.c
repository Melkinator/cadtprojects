#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int locker_id;
    char condition[20];
    bool is_available;
} Locker;

typedef struct {
    int court_id;
    char date[11];  // "YYYY-MM-DD"
    char time[6];   // "HH:MM"
} Booking;

typedef struct {
    int id;
    char name[30];
    Locker locker;      // locker data embedded
    Booking booking;    // booking data embedded
} User;

void registerNewUser(User users[], int size) {
    char nameInput[30];

    printf ("\n===== Register User =====");

    int newId = 1000 + size;    // id start from 1001, 1002...

    // Check for duplication
    for ( int i = 0; i < size; i++)
    {
        if ( users[i].id == newId)
        {
            newId++;    // if the id already exist just increment it to the next one
            break;
        }
    }
    users[size-1].id=newId;   // to set the new id for the user

    printf("\nEnter Your Name: ");
    while (getchar() != '\n');
    scanf("%[^\n]", &nameInput);
    strcpy(users[size-1].name, nameInput);
    strcpy(users[size-1].booking.date, "None");
    strcpy(users[size-1].booking.time, "None");
    users[size-1].booking.court_id = -1; // -1 means no court booked
}

bool isCourtAvailable(User users[], int size, int courtID) {
    for (int i=0;i<size;i++) {
        if (users[i].booking.court_id==courtID) {
            return false; // Court is already booked by another user
        }
    }
    return true; // Court is available
}

void editUser(User User[], int count);
void removeUser(User User[], int *count);
void viewAllUser(User User[], int count);
void displayUserInfo(User u1);        // show name and id only
void saveUserToFile(User User[], int count);
void loadUserFromFile(User User[], int *count);

void bookCourt(User users[], int size) {
    while (getchar() != '\n');
    int input, inputID;
    char inputDate[11], inputTime[6];
    bool end = false; // used to loop back if the court is not available
    if (size==0) {
        printf("\nYou do not have any users registered. Please register a new user before booking.");
    } else if (size>0) {
        printf("\nFor which user do you want to book a court for? (0-%d): ", size-1);
        scanf("%d", &input);
        if (input>=size) {
            printf("\nUser does not exist.");
        } else {
            while (!end) {
                printf("\nWhich court do you want to book: ");
                scanf("%d", &inputID);
                while (getchar() != '\n');
                if (isCourtAvailable(users, size, inputID)) {
                    users[input].booking.court_id = inputID;
                    end = true;
                    printf("\nWhat date do you want to book the court on (DD-MM-YYYY): ");
                    scanf("%[^\n]", &inputDate);
                    while (getchar() != '\n');
                    strcpy(users[input].booking.date, inputDate);
                    printf("\nHow much time are you gonna spend: ");
                    scanf("%[^\n]", &inputTime);
                    strcpy(users[input].booking.time, inputTime);
                } else {
                    printf("\nCourt %d is already booked by another user. Please choose a different court.", inputID);
                }
            }
        }
    }
}



void viewCourtBookings(User users[], int size, int courtCount) {
    if (courtCount>0) {
        printf("\n===== Court Bookings =====\n");
        for (int i=0;i<size;i++) {
            if (users[i].booking.court_id!=-1) {
                printf("\nName: %s\nID: %d\nCourt: %d\nDate: %s\nTime: %s\n", users[i].name, users[i].id, users[i].booking.court_id, users[i].booking.date, users[i].booking.time);
            }
            
        }
    } else {
        printf("\nNo users have booked a court yet. Please book one before trying again.");
    }
}

void cancelCourtBooking(User users[], int size) {
    int input;
    bool end = false; // used to check if input is true
    printf("\nAvailable Courts: ");
    for (int i=0;i<size;i++) {
        if (users[i].booking.court_id!=-1) {
            printf("%d ", users[i].booking.court_id);
        }
    }
    while (!end) {
        printf("\nChoose the court you want to cancel: ");
        scanf("%d", &input);
        for (int i=0;i<size;i++) {
            if (input==users[i].booking.court_id) {
                users[i].booking.court_id = -1; // Reset court booking
                strcpy(users[i].booking.date, "None");
                strcpy(users[i].booking.time, "None");
                printf("\nCourt booking has been cancelled.");
                end = true; // exit loop
                break;
            } else {
                printf("\nCourt %d does not exist. Please try again.", input);
            }
        }
    }
    
}

void assignLocker() {

}

void changeLocker() {

}

void viewLockerStatus() {

}

void viewUserInfo() {
    
}

int main() {
    User *users;
    int size=0; // Used for dynamic memory allocation
    int courtCount=0; // used to check if any court is available or not
    users = malloc(size*sizeof(User));

    bool end = false;
    int input;
    do {
        printf("\n==== Badminton & Locker Management System ====");
        printf("\n1. Register a new user.");
        printf("\n2. Book a badminton court.");
        printf("\n3. View court bookings.");
        printf("\n4. Cancel a court booking.");
        printf("\n5. Assign a locker.");
        printf("\n6. Return/Change locker.");
        printf("\n7. View locker status.");
        printf("\n8. View user info.");
        printf("\n9. Save and exit.\n");
        printf("\nYour input: ");
        scanf("%d", &input);

        system("cls");

        if (users==NULL) {
            printf("Memory Allocation Failed.");
            exit(1);    
        }   

        switch (input) {
            case 1:
                size++;
                User *temp = realloc(users, size*sizeof(User)); // temp to prevent memory leak
                if (temp == NULL) {
                    printf("Memory allocation failed. Exiting program.");
                    free(users);
                    exit(1);
                }
                users = temp; // assign new memory to users after 
                registerNewUser(users, size);
                break;
            case 2:
                courtCount++;
                bookCourt(users, size);
                break;
            case 3:
                viewCourtBookings(users, size, courtCount);
                break;
            case 4:
                if (courtCount>0&&size>0) {
                    courtCount--;
                    cancelCourtBooking(users, size);
                } else {
                    printf("\nNo court has been booked yet. Please book a court before trying again.");
                }
                break;
            case 5:
                assignLocker();
                break;
            case 6:
                changeLocker();
                break;
            case 7:
                viewLockerStatus();
                break;
            case 8:
                viewUserInfo();
                break;
            case 9:
                free(users);
                end = true;
                break;
            default:
                printf("\nWrong input. Please try again.");
                break;
        }
        printf("\nPress Enter key to continue...");
        getchar();
        getchar();
    } while (!end);
    return 0;
}
