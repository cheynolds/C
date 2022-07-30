
/*
Program Description
Adjust program commented below main() to make use of functions. All the same rules from the previous program specifications still apply, for example input gathering, output formatting and breaking on -1 still apply.

Additional requirements.

Write a function that prompts the user for hours worked, rate and name. Use parameter passing, and pass by reference.
Write a function that calculates the gross, base and overtime pay, pass by reference.
Write a function that calculates tax, taking as input the gross pay, returning the tax owed.
Calculate the total amount paid (gross pay) for all 5 people. Use the return value from the function that calculates the gross pay.
Write a print function that generates the output, including the total amount paid, in addition to the data for each employee.
 

Example (Sample input & output for one person)

Enter name: Glenn
Enter hourly rate: 2.00
Enter hours worked: 50
Enter name: -1

Pay to: Glenn

Hours worked:                50.0
Hourly rate:                $    2.00
Gross pay:                   $110.00
Base pay:                    $  80.00
Overtime pay:                         $  30.00

Taxes paid:                 $  22.00
Net pay:                    $  88.00

Total Paid to all employees = $110.00

 (The grand total of payments out.) */

#include <stdio.h>
#include <string.h> 
#define _CRT_SECURE_NO_WARNINGS

//a function that prompts the user for hours worked, rate and name. Use parameter passing, and pass by reference.
void employeeLoadInfo(char name[],float *hours,float *rate,int *empNum)
{ 
        printf("Please enter the NAME of employee #%d: ", *empNum +1);
        scanf("%s", name);
        printf("Please enter the PAY RATE of employee #%d: ", *empNum +1);
        scanf("%f", rate);
        printf("Please enter the HOURS employee #%d worked: ", *empNum +1);
        scanf("%f", hours);
        printf("\n");
} 

//a print function that generates the output, including the total amount paid, in addition to the data for each employee.
void employeePrintInfo(char name[],float *hours,float *rate,int *empNum, float *base, float *gross, float*overtime, float *taxpaid)
{ 
    int local_empNum;
    local_empNum = *empNum +1;
    float net = *gross - *taxpaid;
    
    printf("\n\nEmployee #%d NAME: %s", local_empNum, name);
    printf("\nEmployee #%d HOURS worked: %.1f", local_empNum, *hours);
    printf("\nEmployee #%d RATE hourly: $%.2f", local_empNum, *rate);
    printf("\nEmployee #%d BASE amount: $%.2f", local_empNum, *base);
    printf("\nEmployee #%d GROSS amount: $%.2f", local_empNum, *gross);
    printf("\nEmployee #%d OVERTIME amount: $%.2f", local_empNum, *overtime);
    printf("\nEmployee #%d TAXES paid: $%.2f", local_empNum, *taxpaid);
    printf("\nEmployee #%d NET paid: $%.2f", local_empNum, net);
} 

//a function that calculates the gross, base and overtime pay, pass by reference.
//calculate the total amount paid (gross pay) for all 5 people. 
//use the return value from the function that calculates the gross pay.
//parameter notes: hours and rate are passed by value, gross base and overtime
//are passed by reference so the value can be updated after calculating
float employeeCalcgross(float *hours, float *rate, float *gross, float *base, float *overtime)
{   
    if (*hours <= 40.0f)
    {
        *base = *hours * *rate;
        *overtime = 0.0f;
        *gross = *base;
    }
    else if (*hours > 40.0f)
    {
        *base = (40.0f) * *rate;
        *overtime = (*hours - 40.0f) * *rate * 1.5f;
        *gross = *base + *overtime;
    }
    return *gross;
}

//a function that calculates tax, taking as input the gross pay, returning the tax owed.
float employeeCalctax(float gross)
{
    float tax = 0.0f;
    tax = gross * 0.2f;
    return tax;
}

void splash()
{
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 3.0\n");
    printf("\n\n");
}

int main(void) 
{
    char name[5][40];
    float hours[5];
    float rate[5];
    float gross[5];
    float base[5];
    float overtime[5];
    float taxpaid[5];
    float totalpaid = 0;
    
    int i = 0;
    int empNum = 0;
    
    //load title, version info (and graphics TBD)
    splash();
    
    //get the employee name, hours worked and hourly pay rate
        for (int i = 0; i < 5; i++)
        {
            //call function and pass char* array and float arrays by reference
            employeeLoadInfo(name[i], &hours[i], &rate[i], &empNum);
            if (name[i][0] == '-' && name[i][1] == '1') 
            {
                break;
            }
            else if (hours[i] == -1 || rate[i] == -1) 
            {
                break;
            }
            empNum ++;
        }
        //reset count 
        empNum = 0;
    
    //calculate the gross base and overtime
    for (int i = 0; i < 5; i++)
    {
        
        totalpaid += employeeCalcgross(&hours[i], &rate[i], &gross[i], &base[i], &overtime[i]);

    }
    
    //calculate the tax
    for (int i = 0; i < 5; i++)
    {
        taxpaid[i] = employeeCalctax(gross[i]);
    }
    
    //output the employee payroll report
    for (int i = 0; i < 5; i++)
    {
        employeePrintInfo(name[i], &hours[i], &rate[i], &empNum, &gross[i], &base[i], &overtime[i], &taxpaid[i]);
        empNum ++;
    }
    //print total paid to employees
    printf("\n\nTOTAL PAYROLL COST: $%.2f", totalpaid);

}
/*
Payroll Application 2.0

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
//Please enter the name of employee #1: Please enter the hourly rate of employee #1: Please enter the hours worked by employee #1: Please enter the name of employee #2: Please enter the hourly rate of employee #2: Please enter the hours worked by employee #2: Please enter the name of employee #3: Please enter the hourly rate of employee #3: Please enter the hours worked by employee #3: Please enter the name of employee #4: Please enter the hourly rate of employee #4: Please enter the hours worked by employee #4: Please enter the name of employee #5: Please enter the hourly rate of employee #5: Please enter the hours worked by employee #5:
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
------

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
*/
