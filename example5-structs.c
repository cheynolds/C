#include <stdio.h>
#include <string.h>

struct myStructure
{
	int field1;
	char field2;
	char field3array[20];
};

void printMyStruct(struct myStructure bobo)
{
	printf("%d %c %s\n", bobo.field1, bobo.field2, bobo.field3array);

	printf("Memory addresses\n%p: the variable\n%p: field1\n%p: field2\n%p: field 3\n",
		&bobo, &bobo.field1, &bobo.field2, bobo.field3array);
}

int main() 
{	
	struct myStructure bob = { 1, '2', "third" };
	printf("%d %c %s\n", bob.field1, bob.field2, bob.field3array);

	bob.field1 = 20;
	bob.field2 = 'A';
	strcpy(bob.field3array, "New data");
	printf("%d %c %s\n", bob.field1, bob.field2, bob.field3array);

	printf("Memory addresses\n%p: the variable\n%p: field1\n%p: field2\n%p: field 3\n",
		&bob, &bob.field1, &bob.field2, bob.field3array);

	printMyStruct(bob);

	return 0;
}
