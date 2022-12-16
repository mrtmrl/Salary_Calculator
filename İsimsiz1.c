#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 25
#define MIN_WORKING_HOURS 40
#define BONUS_FEE_WEEKDAY 35
#define BONUS_FEE_WEEKEND 50
#define BONUS_FEE_WEEKDAY_EXTRA 5
#define BONUS_FEE_WEEKEND_EXTRA 80

// Nested structure to store employee information
struct Employee {
    char name[100];
    int id;
    int salary;
    struct {
        int hours;
        int weekday; // 1 if weekday, 2 if weekend
    } workingHours;
};

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees, i, extraHours, bonus;
    FILE *file;

    // Read employee information from user
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);
    for (i = 0; i < numEmployees; i++) {
        printf("Enter name: ");
        scanf("%s", employees[i].name);
        printf("Enter : ");
        scanf("%d", &employees[i].id);
        printf("Enter : ");
        scanf("%d", &employees[i].salary);
        printf("Enter weekly working hour of the employee: ");
        scanf("%d", &employees[i].workingHours.hours);
        printf("Enter weekly working day of the employee(1 2-WEEKEND): ");
        scanf("%d", &employees[i].workingHours.weekday);
        printf("Salary of %s is %d\n", employees[i].name, employees[i].salary);
        printf("*****************\n");
    }
    // Calculate bonus for each employee
    for (i = 0; i < numEmployees; i++) {
        if (employees[i].workingHours.hours > MIN_WORKING_HOURS) {
            extraHours = employees[i].workingHours.hours - MIN_WORKING_HOURS;
            if (employees[i].workingHours.weekday) {
                // Weekday
                if (extraHours > BONUS_FEE_WEEKDAY_EXTRA) {
                    bonus = BONUS_FEE_WEEKDAY_EXTRA * BONUS_FEE_WEEKDAY + (extraHours - BONUS_FEE_WEEKDAY_EXTRA) * BONUS_FEE_WEEKDAY_EXTRA;
                } else {
                    bonus = extraHours * BONUS_FEE_WEEKDAY;
                }
            } else {
                // Weekend
                if (extraHours > BONUS_FEE_WEEKEND_EXTRA) {
                    bonus = BONUS_FEE_WEEKEND_EXTRA * BONUS_FEE_WEEKEND + (extraHours - BONUS_FEE_WEEKEND_EXTRA) * BONUS_FEE_WEEKEND_EXTRA;
                } else {
                    bonus = extraHours * BONUS_FEE_WEEKEND;
                }
            }
            employees[i].salary += bonus;
        }
		
	}
	
	file = fopen("salaries.txt","w");
	  if (file != NULL) {
        for (i = 0; i < numEmployees; i++) {
            fprintf(file, "Name: %s\nTotal Salary: %d\n", employees[i].name, employees[i].salary);
        }
        fclose(file);
    }
    return 0;
}    
			
    
	

