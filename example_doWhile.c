
/*
Define two integer variables.
Ask the user for a value to load into the first variable.
Inside a do-while loop.
Print out the first value.
Ask for another value.
Loop again if the second value is larger than the first.
*/

#include <stdio.h>

int main()
{
    int numberOne = 0;
    int numberTwo = 0;
    
    do {
    printf("Enter a number: ");
    scanf("%d", &numberOne);
    printf("The number entered was %d\n", numberOne);
    printf("Enter another number: ");
    scanf("%d", &numberTwo);
    } while(numberTwo > numberOne);

    return 0;
    
}
