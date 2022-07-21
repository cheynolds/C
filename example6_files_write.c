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

	fprintf(dataFileToBeCreated, "Stuff that I want to write.\n");
	fprintf(dataFileToBeCreated, "x is %d\n", 5);

	fputs("Some stext that I also want to write to the disk.\n", dataFileToBeCreated);
	fputs("Some stext that I also want to write to the disk.\n", dataFileToBeCreated);

	fputc(65, dataFileToBeCreated);
	fputc(10, dataFileToBeCreated);
	fputc(13, dataFileToBeCreated);

	fclose(dataFileToBeCreated);	

	return 0;
}
