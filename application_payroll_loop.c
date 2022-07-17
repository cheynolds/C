#include <stdio.h>
#include <string.h>

int main()
{

    char employeeName[5][20] = {0};
    float employeeRate[5][1] = {0};
    float employeeHours[5][1] = {0};
    float employeeGross[5][1] = {0};
    float employeeTax[5][1] = {0};
    float employeeOverage[5][1] = {0};
    float employeeTakehome[5][1] = {0};
    
    int i=0;
    int exitCheck=0;

    // scan 5 employees information into array
    for(i=0; i<5; i++)
    {
        printf("Please enter the name of employee #%d: ", i+1);
        scanf("%s", employeeName[i]);
        if(strcmp(employeeName[i], "-1") == 0)
            break;
        
        printf("Please enter the hourly rate of employee #%d: ", i+1);
        scanf("%f", employeeRate[i]);
        if(*employeeHours[i] == -1)
            break;
            
        printf("Please enter the hours worked by employee #%d: ", i+1);
        scanf("%f", employeeHours[i]);
        if(*employeeGross[i] == -1)
            break;
      

    }
    
    

    // print all values from array
    for (int i = 0; i < 5; i++)
    {
        printf("\nEmployee #%d: %s\n", i+1, employeeName[i]);
        printf("\nEmployee #%d rate: %.2f\n", i+1, *employeeRate[i]);
        printf("\nEmployee #%d hourly rate: %.2f\n", i+1, *employeeHours[i]);
    }
    
  return 0;
}
