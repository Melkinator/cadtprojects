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
    char id[10];
    char name[30];
    Locker locker;      // locker data embedded
    Booking booking;    // booking data embedded
} User;

void registerNewUser() {

}

void bookCourt() {

}

void viewCourtBookings() {

}

void cancelCourtBooking() {

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

        switch (input) {
            case 1:
                registerNewUser();
            case 2:
                bookCourt();
            case 3:
                viewCourtBookings();
            case 4:
                cancelCourtBooking();
            case 5:
                assignLocker();
            case 6:
                changeLocker();
            case 7:
                viewLockerStatus();
            case 8:
                viewUserInfo();
            case 9:
                end = true;
                break;
            default:
                printf("\nWrong input. Please try again.");
                break;
        }
        printf("\nPress Enter key to go back to the menu or exit.");
        getchar();
        getchar();
    } while (!end);
    return 0;
}
