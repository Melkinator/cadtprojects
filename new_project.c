#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[50];
    char student_id[15];
    int locker_id; // -1 if no locker
    int booked_court; // 0 if none
} User;

typedef struct {
    int court_id;
    char date[11];     // "YYYY-MM-DD"
    char time[6];      // "HH:MM"
    char booked_by[15]; // student_id
    bool is_booked;
} CourtBooking;

typedef struct {
    int locker_id;
    bool is_available;
    char assigned_to[15]; // student_id
    char condition[20];   // e.g., "Good", "Damaged"
} Locker;
// testbr
int main() {
    printf("test");
    return 0;
}
