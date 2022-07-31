#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct Employees 
{
    char name[40];
    int empID;
    float hours;
    float rate;
    float gross;
    float base;
    float overtime;
    float taxpaid;
    float totalpaid;
} employee;

void exit(int status);
void loadMenu();
void splash();
employee processMenu();
employee addRecord();
employee updateRecord();
employee printRecord_single();
employee printRecord_all();

int main(void) 
{
    int i = 0;
    int j = 0;
    struct Employees employee[i];
    splash();
    loadMenu();
    return 0;
    
}

employee addRecord()
{
    /*for (int i = 0; i < 5; i++);
            {
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
            */
           // empNum = 0;
}
employee updateRecord()
{
    ;
}
employee printRecord_single()
{
    ;

}
employee printRecord_all()
{
    ;
}



void splash()
{
    printf("Welcome to Payola: A Payroll System\n");
    printf("Version 4.0\n");
    printf("\n\n");
}


employee processMenu(int menuInput)
{
    printf("menu input %d", menuInput);
    //delete before upload
    switch(menuInput) 
    {
        case 0:
            loadMenu();
        case 1:
            puts("\nYour selection: 1 - ADD a record\n");
            addRecord();
            loadMenu();
        case 2:
            puts("\nYour selection: 2 - UPDATE a record\n");
            updateRecord();
            loadMenu();
        case 3  :
            puts("\nYour selection: 3 - PRINT SINGLE record\n");
            printRecord_single();
            loadMenu();
        case 4 :
            puts("\nYour selection: 4 - PRINT ALL records\n");
            printRecord_all();
            loadMenu();
        case 5 :
            puts("\nGoodbye!\n");
            exit(0);
        default :
            puts("Invalid input! Try again");
            loadMenu();
    } 
    //return 0;
}
void loadMenu()
{
    
    int menuInput = 0;
    puts("\n\nEnter a selection to continue: \n");
    puts("Press 1 to ADD a record\n");
    puts("Press 2 to UPDATE a record\n");
    puts("Press 3 to PRINT a record\n");
    puts("Press 4 to PRINT ALL records\n");
    puts("Press 5 to EXIT application\n");
    scanf(" %d", &menuInput);
    processMenu(menuInput);
}

