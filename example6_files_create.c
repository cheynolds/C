CreateTextFile.c
Who has access

System properties
Type
Text
Size
351 bytes
Storage used
351 bytes
Location
Code
Owner
Glenn Cuevas
Modified
8:41 PM by Glenn Cuevas
Created
8:41 PM
No description
Viewers can download
#include <stdio.h>
#include <string.h>


int main() 
{
	// the name of the file, and how to interact with that file
	FILE* dataFileToBeCreated = fopen("myDataFile.txt", "w");

	if (dataFileToBeCreated == 0)
	{
		puts("Failed to open file, do you have the path correct?");
		return -1;
	}

	fclose(dataFileToBeCreated);	

	return 0;
}
