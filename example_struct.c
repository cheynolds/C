/*Define a structure that has the following fields:
3 floats to represent use input.
1 float to represent the average.
*/
  
#include <stdio.h>

struct userInputs {
    float input1;
    float input2;
    float input3;
    float average;
}Input;

int main()
{

    puts("enter three numbers to find the average");
    scanf("%f %f %f", &Input.input1, &Input.input2, &Input.input3);
    Input.average = (Input.input1+Input.input2+Input.input3)/3;
    printf("Your average is : %0.2f", Input.average);
    return 0;
}
