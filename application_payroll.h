/*
Payroll Application

Write a program that reads in the first name, hourly rate and number of hours worked for 5 people.
Print the following details for each employee.
Name of employee
The number of hours worked
Their weekly gross pay
This is calculated by multiplying hours worked times hourly rate.
If hours worked per week is greater than 40, then overtime needs to also be included.
Overtime pay is calculated as the number of hours worked beyond 40 * rate * 1.5
Taxes withheld
Our tax system is simple, the government gets 20% of the gross pay.
Net paid
The amount of the check issued to the employee.


Example

Enter name: Glenn
Enter hourly rate: 4.00
Enter hours worked: 20

Pay to: Glenn
Hourly rate: $4.00
Hours worked: 20.0

Gross paid: $80.00
Taxes paid: $16.00
Take home: $64.00


Enter name: Stephanie
Enter hourly rate: 49.75
Enter hours worked: 60.5

Pay to: Stephanie
Hourly rate: $49.75
Hours worked: 60.5

Gross paid: $3519.81
Taxes paid: $703.96
Take home: $2815.85

Math used for Stephanie.

Gross paid = 40 * 49.75 -> $1,990
Plus the amount earned working overtime = 20.5 * 49.75 * 1.5 -> 1529.8125
Yields $3,519.81, as a greedy company, who only pays overtime because it's the lay, we'll keep that extra quarter penny.


And so on for employees 3 - 5
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
    float employeeOne_takeHome = 0.0f;
    char employeeTwo[20];
    float employeeTwo_rate = 0.0f;
    float employeeTwo_hours = 0.0f;
    float employeeTwo_gross = 0.0f;
    float employeeTwo_tax = 0.0f;
    float employeeTwo_takeHome = 0.0f;
    char employeeThree[20];
    float employeeThree_rate = 0.0f;
    float employeeThree_hours = 0.0f;
    float employeeThree_gross = 0.0f;
    float employeeThree_tax = 0.0f;
    float employeeThree_takeHome = 0.0f;
    char employeeFour[20];
    float employeeFour_rate = 0.0f;
    float employeeFour_hours = 0.0f;
    float employeeFour_gross = 0.0f;
    float employeeFour_tax = 0.0f;
    float employeeFour_takeHome = 0.0f;
    char employeeFive[20];
    float employeeFive_rate = 0.0f;
    float employeeFive_hours = 0.0f;
    float employeeFive_gross = 0.0f;
    float employeeFive_tax = 0.0f;
    float employeeFive_takeHome = 0.0f;
    float taxrate = 0.2f;
    
    printf("Welcome to Payola: A Payrol System\n");
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
    //clear 
    
    //Clear newline character from buffer
    //https://stackoverflow.com/questions/20150845/c-program-skips-fgets
    getchar();
   //calculations
    employeeOne_gross = employeeOne_rate * employeeOne_hours;
    employeeOne_tax = employeeOne_gross * taxrate;
    employeeOne_takeHome = employeeOne_gross - employeeOne_tax;
    
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
    employeeTwo_gross = employeeTwo_rate * employeeTwo_hours;
    employeeTwo_tax = employeeTwo_gross * taxrate;
    employeeTwo_takeHome = employeeTwo_gross - employeeTwo_tax;
   
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
    employeeThree_gross = employeeThree_rate * employeeThree_hours;
    employeeThree_tax = employeeThree_gross * taxrate;
    employeeThree_takeHome = employeeThree_gross - employeeThree_tax;
    
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
    employeeFour_gross = employeeFour_rate * employeeFour_hours;
    employeeFour_tax = employeeFour_gross * taxrate;
    employeeFour_takeHome = employeeFour_gross - employeeFour_tax;
    
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
    employeeFive_gross = employeeFive_rate * employeeFive_hours;
    employeeFive_tax = employeeFive_gross * taxrate;
    employeeFive_takeHome = employeeFive_gross - employeeFive_tax;
    
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
