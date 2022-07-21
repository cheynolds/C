/*

WITHOUT POINTER
------------------------------------
#include <stdio.h>
int add_one(int x) 
{
    x += 1;
    return x;
}

int main(void) 
{
    int y = 2337;
    printf("y = %d\n", y);
    y = add_one(y);
    printf("y = %d\n", y);
    return 0;
}
*/


//WITH POINTERS
//-------------------------------------


#include <stdio.h>

//code takes a pointer to an integer (*x) and then increments the value by one
void add_one(int *x) 
{
    *x += 1;
}

//assign 2337 to y, print out the current value, increment the value by one, and then print out the modified value
int main(void) 
{
    int y = 2337;
    printf("y = %d\n", y);
    add_one(&y);
    printf("y = %d\n", y);
    return 0;
}
