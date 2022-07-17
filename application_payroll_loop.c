#include <stdio.h>
#include <string.h>

void splash();
void payroll();

int main()
{
    
    splash();
    payroll();

  return 0;
}

void payroll()
{
    char employeeName[5][20] = {0};
    float employeeRate[5][1] = {0};
    float employeeHours[5][1] = {0};
    float employeeGross[5][1] = {0};
    float employeeTax[5][1] = {0};
    float employeeOverage[5][1] = {0};
    float employeeOvertime[5][1] = {0};
    float employeeTakehome[5][1] = {0};
    float employeeBase[5][1] = {0};
    
    int i=0;
    float taxrate = 0.2f;
    float overtime_rate = 1.5f;
    int fulltime_hours = 40;
    int exitCheck=0;
    for(i=0; i<5; i++)
    {
        printf("Please enter the name of employee #%d: ", i+1);
        scanf("%s", employeeName[i]);
        if(strcmp(employeeName[i], "-1") == 0)
            break;
        
        printf("Please enter the hourly rate of employee #%d: ", i+1);
        scanf("%f", employeeRate[i]);
        if(*employeeRate[i] == -1)
            break;
            
        printf("Please enter the hours worked by employee #%d: ", i+1);
        scanf("%f", employeeHours[i]);
        if(*employeeHours[i] == -1)
            break;
    }
    
    // print employee output with payroll calculations
    for (int i = 0; i < 5; i++)
    {
        printf("Employee #%d: %s\n", i+1, employeeName[i]);
        printf("Employee #%d hours worked: %.1f\n", i+1, *employeeHours[i]);
        printf("Employee #%d hourly rate: $%.2f\n", i+1, *employeeRate[i]);

        if (*employeeHours[i] <= 40)
        {
            *employeeGross[i] = *employeeRate[i] * *employeeHours[i];
            *employeeTax[i] = *employeeGross[i] * taxrate;
            *employeeTakehome[i] = *employeeGross[i] - *employeeTax[i];
        }
        else
        {
            *employeeOverage[i] = *employeeHours[i] - 40;
            *employeeBase[i] = 40 * *employeeRate[i];
            *employeeOvertime[i] = (overtime_rate * *employeeRate[i] * *employeeOverage[i]);
            *employeeGross[i] = *employeeBase[i] + *employeeOvertime[i]; 
            *employeeTax[i] =  *employeeGross[i] * taxrate;
            *employeeTakehome[i] = *employeeGross[i] - *employeeTax[i];
        }
        
        printf("Employee #%d gross pay: $%.2f\n", i+1, *employeeGross[i]);
        printf("Employee #%d base pay: $%.2f\n", i+1, *employeeBase[i]);
        printf("Employee #%d overtime pay: $%.2f\n", i+1, *employeeOvertime[i]);
        printf("Employee #%d taxes paid: $%.2f\n", i+1, *employeeTax[i]);
        printf("Employee #%d net pay: $%.2f\n\n\n", i+1, *employeeTakehome[i]);
    }
}


void splash()
{
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 2.0\n");
    printf("\n\n");
}
