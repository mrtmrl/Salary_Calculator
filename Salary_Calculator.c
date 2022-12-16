#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 25
#define MIN_WORKING_HOURS 40
#define BONUS_FEE_WEEKDAY 35
#define BONUS_FEE_WEEKEND 50
#define BONUS_FEE_WEEKDAY_EXTRA 50
#define BONUS_FEE_WEEKEND_EXTRA 80

struct Employee 
{
    char name[100];
    int id;
    int salary;
    struct 
	{
        int hours;
        int weekday;
    } workingHours;
};

int main()
{
    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees, i, extraHours, bonus;
    FILE *file;

    printf("Enter the count of the employee: ");
    scanf("%d", &numEmployees);
    
    for (i = 0; i < numEmployees; i++) 
	{
        printf("Enter the name of the employee: ");
        scanf("%s", employees[i].name);
        printf("Enter the ID of the employee: ");
        scanf("%d", &employees[i].id);
        printf("Enter the salary of the employee: ");
        scanf("%d", &employees[i].salary);
        printf("Enter weekly working hour of the employee: ");
        scanf("%d", &employees[i].workingHours.hours);
        
        if(employees[i].workingHours.hours > MIN_WORKING_HOURS)
        {
       		printf("Enter the weekly working day of the employee(1-WEEKDAY 2-WEEKEND): ");
        	scanf("%d", &employees[i].workingHours.weekday);	
		}
	
        if (employees[i].workingHours.hours > MIN_WORKING_HOURS) 
		{
            extraHours = employees[i].workingHours.hours - MIN_WORKING_HOURS;
            
            if (employees[i].workingHours.weekday==1) 
			{
                if (extraHours >= 5 ) 
				{
                    bonus = BONUS_FEE_WEEKDAY_EXTRA * extraHours;
                } 
				else
				{
                    bonus = extraHours * BONUS_FEE_WEEKDAY;
                }
            } 
			if (employees[i].workingHours.weekday==2)
			{
                if (extraHours >= 5 ) 
				{
                    bonus = extraHours * BONUS_FEE_WEEKEND_EXTRA;
                } 
				else
				{
                    bonus = extraHours * BONUS_FEE_WEEKEND;
                }
            }
            
            employees[i].salary += bonus;
        }
        
		printf("Salary of %s is %d\n", employees[i].name, employees[i].salary);
		printf("*****************\n"); 
	}
	
	file = fopen("salaries.txt","w");
	  if (file != NULL) 
	  {
        for (i = 0; i < numEmployees; i++) 
		{
            fprintf(file, "Name: %s\nTotal Salary: %d\n", employees[i].name, employees[i].salary);
        }
        fclose(file);
    }
    return 0;
}    
			
    
	
