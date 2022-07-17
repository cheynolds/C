/*
Payroll Application 2.0
CS 36 - IVC Summer 2022
Chris Reynolds
Program 2

SAMPLE INPUT

Glenn
2.00
50
Stephanie
25
50
Kyle
80.24
100
John
48.48
38.9
Ron
49
23.12

SAMPLE OUTPUT

Welcome to Payola: A Payroll System
Version 2.0


Please enter the name of employee #1: Please enter the hourly rate of employee #1: Please enter the hours worked by employee #1: Please enter the name of employee #2: Please enter the hourly rate of employee #2: Please enter the hours worked by employee #2: Please enter the name of employee #3: Please enter the hourly rate of employee #3: Please enter the hours worked by employee #3: Please enter the name of employee #4: Please enter the hourly rate of employee #4: Please enter the hours worked by employee #4: Please enter the name of employee #5: Please enter the hourly rate of employee #5: Please enter the hours worked by employee #5:

Employee #1: Glenn
Employee #1 hours worked: 50.0
Employee #1 hourly rate: $2.00
Employee #1 gross pay: $110.00
Employee #1 base pay: $80.00
Employee #1 overtime pay: $30.00
Employee #1 taxes paid: $22.00
Employee #1 net pay: $88.00

Employee #2: Stephanie
Employee #2 hours worked: 50.0
Employee #2 hourly rate: $25.00
Employee #2 gross pay: $1375.00
Employee #2 base pay: $1000.00
Employee #2 overtime pay: $375.00
Employee #2 taxes paid: $275.00
Employee #2 net pay: $1100.00

Employee #3: Kyle
Employee #3 hours worked: 100.0
Employee #3 hourly rate: $80.24
Employee #3 gross pay: $10431.20
Employee #3 base pay: $3209.60
Employee #3 overtime pay: $7221.60
Employee #3 taxes paid: $2086.24
Employee #3 net pay: $8344.96

Employee #4: John
Employee #4 hours worked: 38.9
Employee #4 hourly rate: $48.48
Employee #4 gross pay: $1885.87
Employee #4 base pay: $0.00
Employee #4 overtime pay: $0.00
Employee #4 taxes paid: $377.17
Employee #4 net pay: $1508.70

Employee #5: Ron
Employee #5 hours worked: 23.1
Employee #5 hourly rate: $49.00
Employee #5 gross pay: $1132.88
Employee #5 base pay: $0.00
Employee #5 overtime pay: $0.00
Employee #5 taxes paid: $226.58
Employee #5 net pay: $906.30

*/

#include <stdio.h>
#include <string.h>

void splash(void);
void payroll(void);

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
    
    // get employee input, check for -1 input to cancel
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
