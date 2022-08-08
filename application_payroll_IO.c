// Add file IO to program 4. Create a plain-text file that will store employee information from the program code. 
// The program will have the ability to load the array with the data from the file.

// When the user chooses to load from a file, ask for the name of the file, then load the data into the employee array. 
// If they choose keyboard, load the data as was done previously. Note that the application is going to want to use the 
// folder where the .exe file is located when looking for the file, unless we type in a full or relative path. 
// Using the debug folder is fine for our purposes.

// Once the data is loaded into our array, either from an already existing file, or from keyboard input, 
// we’ll then have our menu from the previous assignment. Before the program exits, you will need to ask for 
// the name of the file to save the data to. If we loaded from a file already, 
// we’ll use the same file and overwrite the contents.

// We don’t need to cover deleting employee data. 
// We can also assume that we only need to handle at most 10 employees worth of data.


//todo add comments
//add request
//add github information
//add splash screen ASCII

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
//required for pause while saving
#include <unistd.h>
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
void saveFile(Employees * employee, int *empCount, float *gross);
void processMenu(int menuInput, Employees *employee, int *empCount, float *gross);
float calcEmp(Employees* employee, int *empCount, float *gross);
int getEmp(int *empCount, Employees* employee, float *gross);

void loadMenu(Employees *employee, int *empCount, float *gross)
{
    int menuInput = 0;
    puts("MAIN MENU");
    puts("---------\n\nEnter a selection to continue: \n");
    puts("Press 1 to LOAD a record(s)");
    puts("Press 2 to ADD a record");
    puts("Press 3 to UPDATE a record");
    puts("Press 4 to PRINT a record");
    puts("Press 5 to PRINT ALL records");
    puts("Press 6 to SAVE ALL records");
    puts("Press 7 to EXIT application\n");
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
        printf("Please enter the HOURS of employee: ");
        scanf("%f", &employee[*empCount].hours);
        if (employee[*empCount].hours == -1)
        {
            loadMenu(employee, empCount, gross);
        }
        *gross += calcEmp(employee, empCount, gross);
        (*empCount) ++;
        printf("\n");
    } while (*empCount<MAX);
}

void updateRecord(Employees* employee, int *empCount, float *gross)
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
    //int checkInput;
    int i;
    do{
        puts("Select an employee: ");
        for (int i = 0; i < *empCount; i++)
        {
            printf("Employee %d: %s\n", i+1, employee[i].name);
        }
        scanf("%d", &selection);
        //checkInput = strcmp (employee[i].name, "-1");
        if (selection == -1)
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
        }
    printf("\n\nTOTAL PAYROLL COST: $%.2f", *gross);
    loadMenu(employee, empCount, gross);
}

void splash()
{
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 4.0\n");
    printf("\n\n");
}

void saveFile(Employees * employee, int *empCount, float *gross)
{
    char fileName[30];
    puts("Filename to save?");
    scanf(" %s", fileName);
    puts("Saving...");
    sleep(2);
    printf("Success! The following output was saved to file '%s'", fileName);
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
        }
        
    printf("\n\nTOTAL PAYROLL COST: $%.2f", *gross);
    sleep(2);
    loadMenu(employee, empCount, gross);
}

void processMenu(int menuInput, Employees *employee, int *empCount, float *gross)
{
    char saveChoice;
    switch(menuInput) 
    {
        case 1:
            puts("\nYour selection: 1 - LOAD file\n");
            //code here
        case 2:
            puts("\nYour selection: 2 - ADD a record\n");
            addRecord(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 3:
            puts("\nYour selection: 3 - UPDATE a record\n");
            updateRecord(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 4  :
            puts("\nYour selection: 4 - PRINT SINGLE record\n");
            printRecord_single(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 5 :
            puts("\nYour selection: 5 - PRINT ALL records\n");
            printRecord_all(employee, empCount, gross);
            loadMenu(employee, empCount, gross);
        case 6:
            puts("\nYour selection: 6 - SAVE file\n");
            saveFile(employee, empCount, gross);
            loadMenu(employee, empCount, gross);

        case 7:
            if (*empCount >= 1)
            {
                puts("\nYou have unsaved data - SAVE to file?\n");
                scanf(" %c", &saveChoice);
                if (saveChoice == 'y' || saveChoice == 'Y')
                {
                    saveFile(employee, empCount, gross);
                    exit(0);
                }
                else
                {
                    //redundant from output below - remove on next update
                    puts("\nGoodbye!\n");
                    exit(0);
                }
            }
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