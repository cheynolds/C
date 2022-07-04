/*
Program Description
Write a program that prints out your name, the course ID of this class, what programming/computer courses you've taken.
Ask the user for two numbers.
Load the user numbers into variables.
Show the sum of the two numbers, the difference, the product and the quotient.
For the difference subtract the second number from the first, for the quotient, use the first number as the numerator(dividend) and the second as the denominator(divisor).
 

Sample Output:

My name is Glenn, I'm in course 123456. I've taken:
C Programming
C++ Programming

Give me a number: 7
Give me a second number: 2

The sum is 9.
The difference is 5.
The product is 14.
The quotient is 3.

*/

#include <stdio.h>

int main()
{
    int userInput_one = 0;
    int userInput_two = 0;
    int numberSum = 0;
    int numberDifference = 0;
    int numberProduct = 0;
    int numberQuotient = 0;
    
    char userName[] = "YourName";
    char classNumber[] = "ClassNumber";
    
    printf("My name is %s, I'm in course %s. I've taken: \n", userName,classNumber);
    printf("Python programming \n");
    printf("C++ programming \n\n");
    printf("Give me a number: ");
    scanf("%d", &userInput_one);
    printf("Give me another number: ");
    scanf("%d", &userInput_two);
    printf("\n");
    
    numberSum = userInput_one + userInput_two;
    numberDifference = userInput_one - userInput_two;
    numberProduct = userInput_one * userInput_two;
    numberQuotient = userInput_one / userInput_two;
    
    printf("The sum is %d.\n", numberSum);
    printf("The difference is %d.\n", numberDifference);
    printf("The product is %d.\n", numberProduct);
    printf("The quotient is %d.\n", numberQuotient);

    
    return 0;
    
}
