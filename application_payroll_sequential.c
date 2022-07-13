/*
Payroll Application
A simple application to demonstrate the benefits of loops and functions, but done in their absense. 353 lines of code is the starting point.
How much can it be simplied with functions and loops?



SAMPLE OUTPUT
---------------------------
Welcome to Payola: A Payroll System
Version 1.0

Enter name: Glenn
Enter hourly rate: 4.00
Enter hours worked: 20
Enter name: Stephanie
Enter hourly rate: 49.75
Enter hours worked: 60.5
Enter name: John
Enter hourly rate: 39.50
Enter hours worked: 40
Enter name: Kyle
Enter hourly rate: 24.40
Enter hours worked: 99
Enter name: Layla 
Enter hourly rate: 29.3
Enter hours worked: 50

Preparing calculation module...


Loading tax tables...


Calculations Complete! 


-----Payroll Report-----

Pay to: Glenn
Hourly rate: $4.00
Hours worked: 20.0

Gross paid: $80.00
Taxes paid: $16.00
Take home: $64.00


Pay to: Stephanie
Hourly rate: $49.75
Hours worked: 60.5

Gross paid: $3519.81
Taxes paid: $703.96
Take home: $2815.85


Pay to: John
Hourly rate: $39.50
Hours worked: 40.0

Gross paid: $1580.00
Taxes paid: $316.00
Take home: $1264.00


Pay to: Kyle
Hourly rate: $24.40
Hours worked: 99.0

Gross paid: $3135.40
Taxes paid: $627.08
Take home: $2508.32


Pay to: Layla
Hourly rate: $29.30
Hours worked: 50.0

Gross paid: $1611.50
Taxes paid: $322.30
Take home: $1289.20
---------------------------
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    char employeeOne[20];
    float employeeOne_rate = 0.0f;
    float employeeOne_hours = 0.0f;
    float employeeOne_gross = 0.0f;
    float employeeOne_tax = 0.0f;
    float employeeOne_hours_overage = 0.0f;
    float employeeOne_takeHome = 0.0f;
    
    char employeeTwo[20];
    float employeeTwo_rate = 0.0f;
    float employeeTwo_hours = 0.0f;
    float employeeTwo_gross = 0.0f;
    float employeeTwo_tax = 0.0f;
    float employeeTwo_hours_overage = 0.0f;
    float employeeTwo_takeHome = 0.0f;
    
    char employeeThree[20];
    float employeeThree_rate = 0.0f;
    float employeeThree_hours = 0.0f;
    float employeeThree_gross = 0.0f;
    float employeeThree_tax = 0.0f;
    float employeeThree_hours_overage = 0.0f;
    float employeeThree_takeHome = 0.0f;
    
    char employeeFour[20];
    float employeeFour_rate = 0.0f;
    float employeeFour_hours = 0.0f;
    float employeeFour_gross = 0.0f;
    float employeeFour_tax = 0.0f;
    float employeeFour_hours_overage = 0.0f;
    float employeeFour_takeHome = 0.0f;
    
    char employeeFive[20];
    float employeeFive_rate = 0.0f;
    float employeeFive_hours = 0.0f;
    float employeeFive_gross = 0.0f;
    float employeeFive_tax = 0.0f;
    float employeeFive_hours_overage = 0.0f;
    float employeeFive_takeHome = 0.0f;
    
    //Fixed values
    float taxrate = 0.2f;
    float overtime_rate = 1.5f;
    int fulltime_hours = 40;
    
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 1.0\n");
    printf("\n");
    
    //INPUT EmployeeOne
    //request name from user, store to character array
    printf("Enter name: ");
    fgets(employeeOne,20,stdin);
    
    //request payrate from user, store as float
    printf("Enter hourly rate: ");
    scanf("%f", &employeeOne_rate);
    
    //request hours worked from user, store as float
    printf("Enter hours worked: ");
    scanf("%f", &employeeOne_hours);
 
    //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
    
    //calculations
    if (employeeOne_hours <= 40)
    {
        employeeOne_gross = employeeOne_rate * employeeOne_hours;
        employeeOne_tax = employeeOne_gross * taxrate;
        employeeOne_takeHome = employeeOne_gross - employeeOne_tax;
    }
    else
    {
        employeeOne_hours_overage = employeeOne_hours - fulltime_hours;
        employeeOne_gross = (fulltime_hours*employeeOne_rate) + (overtime_rate*employeeOne_rate*employeeOne_hours_overage); 
        employeeOne_tax = employeeOne_gross * taxrate;
        employeeOne_takeHome = employeeOne_gross - employeeOne_tax;
    }    
    
    //INPUT EmployeeTwo
    //request name from user, store to character array
    printf("Enter name: ");
    fgets(employeeTwo,20,stdin);
    
    //request payrate from user, store as float
    printf("Enter hourly rate: ");
    scanf("%f", &employeeTwo_rate);
    
    //request hours worked from user, store as float
    printf("Enter hours worked: ");
    scanf("%f", &employeeTwo_hours);
    
    //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
    
   //calculations
    if (employeeTwo_hours <= 40)
    {
        employeeTwo_gross = employeeTwo_rate * employeeTwo_hours;
        employeeTwo_tax = employeeTwo_gross * taxrate;
        employeeTwo_takeHome = employeeTwo_gross - employeeTwo_tax;
    }
    else
    {
        employeeTwo_hours_overage = employeeTwo_hours - fulltime_hours;
        employeeTwo_gross = (fulltime_hours*employeeTwo_rate) + (overtime_rate*employeeTwo_rate*employeeTwo_hours_overage); 
        employeeTwo_tax = employeeTwo_gross * taxrate;
        employeeTwo_takeHome = employeeTwo_gross - employeeTwo_tax;
    }  
   
   //INPUT EmployeeThree
    //request name from user, store to character array
    printf("Enter name: ");
    fgets(employeeThree,20,stdin);
    
    //request payrate from user, store as float
    printf("Enter hourly rate: ");
    scanf("%f", &employeeThree_rate);
    
    //request hours worked from user, store as float

    printf("Enter hours worked: ");
    scanf("%f", &employeeThree_hours);
   //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
    
   //calculations
   if (employeeThree_hours <= 40)
    {
        employeeThree_gross = employeeThree_rate * employeeThree_hours;
        employeeThree_tax = employeeThree_gross * taxrate;
        employeeThree_takeHome = employeeThree_gross - employeeThree_tax;
    }
    else
    {
        employeeThree_hours_overage = employeeThree_hours - fulltime_hours;
        employeeThree_gross = (fulltime_hours*employeeThree_rate) + (overtime_rate*employeeThree_rate*employeeThree_hours_overage); 
        employeeThree_tax = employeeThree_gross * taxrate;
        employeeThree_takeHome = employeeThree_gross - employeeThree_tax;
    }  
    
    //INPUT EmployeeFour
    //request name from user, store to character array
    printf("Enter name: ");
    fgets(employeeFour,20,stdin);
    
    //request payrate from user, store as float
    printf("Enter hourly rate: ");
    scanf("%f", &employeeFour_rate);
    
    //request hours worked from user, store as float

    printf("Enter hours worked: ");
    scanf("%f", &employeeFour_hours);
   //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
    
   //calculations
    if (employeeFour_hours <= 40)
    {
        employeeFour_gross = employeeFour_rate * employeeFour_hours;
        employeeFour_tax = employeeFour_gross * taxrate;
        employeeFour_takeHome = employeeFour_gross - employeeFour_tax;
    }
    else
    {
        employeeFour_hours_overage = employeeFour_hours - fulltime_hours;
        employeeFour_gross = (fulltime_hours*employeeFour_rate) + (overtime_rate*employeeFour_rate*employeeFour_hours_overage); 
        employeeFour_tax = employeeFour_gross * taxrate;
        employeeFour_takeHome = employeeFour_gross - employeeFour_tax;
    }  
    
    //INPUT EmployeeFive
    //request name from user, store to character array
    printf("Enter name: ");
    fgets(employeeFive,20,stdin);
    
    //request payrate from user, store as float
    printf("Enter hourly rate: ");
    scanf("%f", &employeeFive_rate);
    
    //request hours worked from user, store as float
    printf("Enter hours worked: ");
    scanf("%f", &employeeFive_hours);
    
    //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
    
   //calculations
    if (employeeFive_hours <= 40)
    {
        employeeFive_gross = employeeFive_rate * employeeFive_hours;
        employeeFive_tax = employeeFive_gross * taxrate;
        employeeFive_takeHome = employeeFive_gross - employeeFive_tax;
    }
    else
    {
        employeeFive_hours_overage = employeeFive_hours - fulltime_hours;
        employeeFive_gross = (fulltime_hours*employeeFive_rate) + (overtime_rate*employeeFive_rate*employeeFive_hours_overage); 
        employeeFive_tax = employeeFive_gross * taxrate;
        employeeFive_takeHome = employeeFive_gross - employeeFive_tax;
    }  
    
    //OUTPUT calculated pay 
    printf("\n");
    printf("Preparing calculation module...\n\n\n");
    sleep(1);
    printf("Loading tax tables...\n\n\n");
    sleep(1);
    printf("Calculations Complete! \n\n\n-----Payroll Report-----\n\n");
    sleep(1);
    printf("Pay to: %s", employeeOne);
    
    //output dollar rate as float with format #.##
    printf("Hourly rate: $%.2f\n", employeeOne_rate);
    printf("Hours worked: %.1f\n\n", employeeOne_hours);
    printf("Gross paid: $%.2f\n", employeeOne_gross);
    printf("Taxes paid: $%.2f\n", employeeOne_tax);
    printf("Take home: $%.2f\n", employeeOne_takeHome);
    printf("\n\n");
    printf("Pay to: %s", employeeTwo);
    
    //output dollar rate as float with format #.##
    printf("Hourly rate: $%.2f\n", employeeTwo_rate);
    printf("Hours worked: %.1f\n\n", employeeTwo_hours);
    printf("Gross paid: $%.2f\n", employeeTwo_gross);
    printf("Taxes paid: $%.2f\n", employeeTwo_tax);
    printf("Take home: $%.2f\n", employeeTwo_takeHome);
    printf("\n\n");
    printf("Pay to: %s", employeeThree);
    
    //output dollar rate as float with format #.##
    printf("Hourly rate: $%.2f\n", employeeThree_rate);
    printf("Hours worked: %.1f\n\n", employeeThree_hours);
    printf("Gross paid: $%.2f\n", employeeThree_gross);
    printf("Taxes paid: $%.2f\n", employeeThree_tax);
    printf("Take home: $%.2f\n", employeeThree_takeHome);
    printf("\n\n");
    printf("Pay to: %s", employeeFour);
    //output dollar rate as float with format #.##
    printf("Hourly rate: $%.2f\n", employeeFour_rate);
    printf("Hours worked: %.1f\n\n", employeeFour_hours);
    printf("Gross paid: $%.2f\n", employeeFour_gross);
    printf("Taxes paid: $%.2f\n", employeeFour_tax);
    printf("Take home: $%.2f\n", employeeFour_takeHome);
    printf("\n\n");
    printf("Pay to: %s", employeeFive);
    
    //output dollar rate as float with format #.##
    printf("Hourly rate: $%.2f\n", employeeFive_rate);
    printf("Hours worked: %.1f\n\n", employeeFive_hours);
    printf("Gross paid: $%.2f\n", employeeFive_gross);
    printf("Taxes paid: $%.2f\n", employeeFive_tax);
    printf("Take home: $%.2f\n", employeeFive_takeHome);
    
return 0;

    
}
