#include <stdio.h>
#include <time.h>

void print_calendar(int month, int year) {
    struct tm first_day = {0};
    first_day.tm_mday = 1;  //start with the first day of the month
    first_day.tm_mon = month - 1; // Months are 0-based in tm (January = 0)
    first_day.tm_year = year - 1900; // Years are counted from 1900 in tm

    mktime(&first_day); //normalize the time structure

    int start_day = first_day.tm_wday; //day of the week for the 1st of the month
    int days_in_month;

    //calculate days in the month
    if (month == 2) { //February check for leap year
        days_in_month = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }

    printf("    %d-%02d\n", year, month); //month and year header
    printf("Su Mo Tu We Th Fr Sa\n"); //days of the week

    //leading spaces for the first week
    for (int i = 0; i < start_day; i++) {
        printf("   ");
    }

    // Print the calendar days
    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        if ((day + start_day) % 7 == 0) { //new line after Saturday
            printf("\n");
        }
    }

    printf("\n");
}

int main() {
    int month, year;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Validate input
    if (month < 1 || month > 12 || year < 1) {
        printf("Invalid month or year.\n");
        return 1;
    }

    print_calendar(month, year);

    return 0;
}
