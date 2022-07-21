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

void printAllMyStructs(struct myStructure arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printMyStruct(arr[i]);
	}
}

void resetAllMyStructs(struct myStructure arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		arr[i].field1 = 0;
		arr[i].field2 = 0;
		strcpy(arr[i].field3array, "");
	}
}

int main() 
{	
	struct myStructure bob[5];

	bob[0].field1 = 1;
	bob[0].field2 = '2';
	strcpy(bob[0].field3array, "the string");
	printMyStruct(bob[0]);
	printAllMyStructs(bob, 5);
	resetAllMyStructs(bob, 5);
	printMyStruct(bob[0]);


	return 0;
}
