#include <stdio.h>

int scanfWithReferenceParameter(int* loadMe)
{
	puts("Load what number?");
	scanf("%d", loadMe); // no ampersand
}

int brokenLoadManipulatingThePointer(int* loadMe)
{
	puts("Load what number?");
	scanf("%d", &loadMe);
	// explode on use
}

void avoidTheWrinklesWithTheGoldenRuleUseAMiddleMan(int* byRefernce)
{
	int localVar;
	puts("Load what number");
	scanf("%d", &localVar);
	*byRefernce = localVar;
}

int main()
{ 
  /*declaring a character array 'name' of length 120
	char name[120];
  
  	puts("enter a string");

  // not using the address of operator (&), because it does not
  // change the value of what we are sending to scanf
	scanf("%s", name);
	  //output value of name
	puts(name);
*/



	int loadme;
	scanfWithReferenceParameter(&loadme);
	printf("%d was loaded", loadme);

	brokenLoadManipulatingThePointer(&loadme);
	printf("%d was not changed.", loadme);

	avoidTheWrinklesWithTheGoldenRuleUseAMiddleMan(&loadme);
	printf("%d was changed with middle man.", loadme);
}
