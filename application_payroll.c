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
