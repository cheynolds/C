#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 20

typedef struct  
{
    char name[40];
    int empID;
    float hours;
    float rate;
    float gross;
    float base;
    float overtime;
    float tax;
    float net;

} Employees;

void processMenu(int menuInput, Employees *employee, int *empCount, float *gross);
float calcEmp(Employees* employee, int *empCount, float *gross);
int getEmp(int *empCount, Employees* employee, float *gross);


int loadMenu(Employees *employee, int *empCount, float *gross)
{
    int menuInput = 0;
    puts("\n\nEnter a selection to continue: \n");
    puts("Press 1 to ADD a record\n");
    puts("Press 2 to UPDATE a record\n");
    puts("Press 3 to PRINT a record\n");
    puts("Press 4 to PRINT ALL records\n");
    puts("Press 5 to EXIT application\n");
    scanf(" %d", &menuInput);
    processMenu(menuInput, employee, empCount, gross);

}


void addRecord(Employees* employee, int* empCount, float *gross)
{
    int checkInput = 1;
    if (*empCount == MAX)
    {
        printf("Limit reached! You cannot create more than %d employees!\n", MAX);
        loadMenu(employee, empCount, gross);
    }
    do{
        printf("Please enter the NAME of employee: ");
        scanf(" %s", employee[*empCount].name);
        checkInput = strcmp (employee[*empCount].name, "-1");
        if (checkInput == 0)
        {
            loadMenu(employee, empCount, gross);
        }
        printf("Please enter the PAY RATE of employee:");
        scanf("%f", &employee[*empCount].rate);
        if (employee[*empCount].rate == -1)
        {
            loadMenu(employee, empCount, gross);
        }
        printf("Please enter the HOURS of employee : ");
        scanf("%f", &employee[*empCount].hours);
        if (employee[*empCount].hours == -1)
        {
            loadMenu(employee, empCount, gross);
        }
        *gross += calcEmp(employee, empCount, gross);
        //calcEmp(employee, empCount);
        (*empCount) ++;
        printf("\n");
    } while (*empCount<MAX);
}

float updateRecord(Employees* employee, int *empCount, float *gross)
{
    int selection = getEmp(empCount, employee, gross);
    int checkInput=1;
    
    printf("Please enter the NAME of employee: ");
    scanf(" %s", employee[selection].name);
    checkInput = strcmp (employee[selection].name, "-1");
    if (checkInput == 0)
    {
        loadMenu(employee, empCount, gross);
    }
    printf("Please enter the PAY RATE of employee:");
    scanf("%f", &employee[selection].rate);
    if (employee[selection].rate == -1)
    {
        loadMenu(employee, empCount, gross);
    }

    printf("Please enter the HOURS of employee : ");
    scanf("%f", &employee[selection].hours);
    if (employee[selection].hours == -1)
    {
        loadMenu(employee, empCount, gross);
    }
    *gross += calcEmp(employee, empCount, gross);
    //(*empCount) ++;
    printf("\n");
}

float calcEmp(Employees* employee, int *empCount, float *gross)
{
    if (employee[*empCount].hours <= 40.0f)
    {
        employee[*empCount].base = employee[*empCount].hours * employee[*empCount].rate;
        employee[*empCount].overtime = 0.0f;
        employee[*empCount].gross = employee[*empCount].base;
        
    }
    else if (employee[*empCount].hours > 40.0f)
    {
        employee[*empCount].base = (40.0f) * employee[*empCount].rate;
        employee[*empCount].overtime = (employee[*empCount].hours - 40.0f) * employee[*empCount].rate * 1.5f;
        employee[*empCount].gross = employee[*empCount].base + employee[*empCount].overtime;
    }
    employee[*empCount].tax = employee[*empCount].gross * 0.2f;
    employee[*empCount].net = employee[*empCount].gross - employee[*empCount].tax;

    return employee[*empCount].gross;
}



int getEmp(int *empCount, Employees* employee, float *gross)
{
    int selection;
    int checkInput;
    int i;
    do{
        puts("Select an employee: ");
        for (int i = 0; i < *empCount; i++)
        {
            printf("Employee %d: %s\n", i+1, employee[i].name);
        }
        scanf("%d", &selection);
        checkInput = strcmp (employee[i].name, "-1");
        if (checkInput == 0)
        {
            loadMenu(employee, empCount, gross);
        }
    } while (selection > (*empCount + 1) || selection < 1);
    
    selection--;
    return selection;
}

void printRecord_single(Employees* employee, int *empCount, float *gross)
{
    int selection = getEmp(empCount, employee, gross);
    printf("\n\nEmployee #%d NAME: %s", selection+1, employee[selection].name);
    printf("\nEmployee #%d HOURS worked: %.1f",selection+1, employee[selection].hours);
    printf("\nEmployee #%d RATE hourly: $%.2f",selection+1, employee[selection].rate);
    printf("\nEmployee #%d BASE amount: $%.2f", selection+1, employee[selection].base);
    printf("\nEmployee #%d GROSS amount: $%.2f", selection+1, employee[selection].gross);
    printf("\nEmployee #%d OVERTIME amount: $%.2f", selection+1, employee[selection].overtime);
    printf("\nEmployee #%d TAXES paid: $%.2f", selection+1, employee[selection].tax);
    printf("\nEmployee #%d NET paid: $%.2f", selection+1, employee[selection].net);
    loadMenu(employee, empCount, gross);
}

  
void printRecord_all(Employees * employee, int *empCount, float *gross)
{
     for (int i = 0; i < *empCount; i++)
        {
            printf("\n\nEmployee #%d NAME: %s", i+1, employee[i].name);
            printf("\nEmployee #%d HOURS worked: %.1f", i+1, employee[i].hours);
            printf("\nEmployee #%d RATE hourly: $%.2f", i+1, employee[i].rate);
            printf("\nEmployee #%d BASE amount: $%.2f", i+1, employee[i].base);
            printf("\nEmployee #%d GROSS amount: $%.2f", i+1, employee[i].gross);
            printf("\nEmployee #%d OVERTIME amount: $%.2f", i+1, employee[i].overtime);
            printf("\nEmployee #%d TAXES paid: $%.2f", i+1, employee[i].tax);
            printf("\nEmployee #%d NET paid: $%.2f", i+1, employee[i].net);
            printf("\n\nTOTAL PAYROLL COST: $%.2f", *gross);

        }
    loadMenu(employee, empCount, gross);
}

void splash()
{
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 4.0\n");
    printf("\n\n");
}


void processMenu(int menuInput, Employees *employee, int *empCount, float *gross)
{
    switch(menuInput) 
    {
        case 1:
            puts("\nYour selection: 1 - ADD a record\n");
            addRecord(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 2:
            puts("\nYour selection: 2 - UPDATE a record\n");
            updateRecord(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 3  :
            puts("\nYour selection: 3 - PRINT SINGLE record\n");
            printRecord_single(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 4 :
            puts("\nYour selection: 4 - PRINT ALL records\n");
            printRecord_all(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 5 :
            puts("\nGoodbye!\n");
            exit(0);
        default :
            puts("Invalid input! Try again");
            loadMenu(employee, empCount, gross);
    } 
}

int main(void) 
{   
    splash();
    int selection;
    int empCount = 0;
    float gross = 0.2f;
    Employees employee[MAX];
    loadMenu(employee, &empCount, &gross);
    return 0;
}
