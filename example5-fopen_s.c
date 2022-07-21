
#include <stdio.h>
#include <string.h>

void Load(int* x)
{
	*x = 25;
}

void Load1(int** x)
{
	*x = 0x21ffabcd00;
}

int main()
{
	int x = 1;
	int* p = &x;
	Load(&x);
	Load1(&p);
	// both x & p are altered, as we passed where in memory they were

	char fileName[50];
	puts("Name of the file?");
	scanf("%s", fileName);

	FILE* dataFileToBeCreated;
	int error = fopen_s(&dataFileToBeCreated, fileName, "w");

	if (error != 0)
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
