
OPTIONAL:
int searchUserByID    (User User[], int count, char *id);
void displayUserInfo    (User u1);

For vichet:  Manage Booking  (IN THE PARAMETER WE CANT JUST CHANGE IT, THIS IS just a Sample)

void bookCourt            (Player players[], int count);
bool isCourtAvailable       (Player players[], int count, int court_id, char date[], char time[]);
void cancelCourtBooking       (Player players[], int count);
void viewCourtBookings          (Player players[], int count);
void viewBookingByStudent        (Player players[], int count, char *id);


For Sakal : Locker management

void assignLocker    (Player players[], int count);
void returnLocker      (Player players[], int count);
void viewLockerStatus    (Player players[], int count);
void viewLockerByStudent  (Player players[], int count, char *id);
bool isLockerAvailable      (Player players[], int count, int locker_id);


For Tong: User Information


void addUser    (User User[], int *count);
void editUser    (User User[], int count);
void removeUser    (User User[], int *count);
void viewAllUser          (User players[], int count);
void saveUserToFile         (User User[], int count);
void loadUserFromFile          (User User[], int *count);
