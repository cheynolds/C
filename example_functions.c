/*
Example, 
Defining a Function
Calling a Function
Returning a Function Result

#include <stdio.h>

//function declarations
int checkGuess(int paramter);

int main()
{
    //global variable declaration

    int paramter = 20;
    int output = 0;
    
    // calling function as variable declaration
    output = checkGuess(paramter);
    printf("%d", output);
    return 0;
}

// function asks for user input and provides result based on comparison statements
int checkGuess(int paramter)
{
    //local variable declarations
    int userGuess = 1;
    int result = 0;
    printf("Guess the number: \n");
    scanf("%d", &userGuess);
    
    if (userGuess < paramter)
    {
        return result = -1;
    }
    else if (userGuess > paramter)
    {
        return result = 1;
    }
    
    else
    {
        return result = 0;
    }
    
}
