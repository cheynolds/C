#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double leftside = 0, rightside = 0;

	puts("Welcome to our calculator!");

	puts("What is the left hand side operator?");
	scanf("%lf", &leftside);

	puts("What is the right hand side operator?");
	scanf("%lf", &rigthside);

	puts("What operator?");

	char operation = 'x';
	//scanf("%c", &operation); 
  //fails - reads a \n (new line) because it is still in the buffer, add space
	scanf(" %c", &operation);

	printf("%lf %c %lf = ", leftside, operation, rightside);

	switch (operation)
	{
	case '+':
		printf("%lf\n", leftside + rightside);
		break; // jump statement, jumps to the next statement of code after the switch body
	case '-':
		printf("%lf\n", leftside - rightside);
		break;
	case '*':
		printf("%lf\n", leftside * rightside);
		break;
	case '/':
		printf("%lf\n", leftside / rightside);
		break;
	}

	puts("switch operation completed.");

	return 0;
}
