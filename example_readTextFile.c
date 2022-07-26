/*#include <stdio.h>

int main()
{
    FILE* txtFile = fopen("data2.txt", "r");
    if (txtFile == 0)
    {
        puts("Can't find file");
        return;
    }

    char firstName[25];
    char middleName[25];    
    char lastName[25];

    fscanf(txtFile, "%s", &firstName);
    fscanf(txtFile, "%s", &middleName);
    fscanf(txtFile, "%s", &lastName);

    printf("%s %s %s\n", firstName, middleName, lastName);

    fclose(txtFile);

    return 0;
}

*/

int main()
{

    char name[10] = "bob";
    float  hours = 23;
    float rate = 45.45;

    FILE* output = fopen("output.txt", "w");
    if (output == 0)
    {
        puts("Can't open file");
        return;
    }

    fprintf(output, "Name %s\nHours %f\nRate %f\n",
        name, hours, rate);

    fclose(output);

    FILE* dataFile = fopen("datafile.txt", "w");

    fprintf(dataFile, "%s\n%f\n%f\n",
        name, hours, rate);
    fclose(dataFile);

    // try to read the output file to get the employee data

    FILE* input = fopen("output.txt", "r");
    if (input == 0)
    {
        puts("Can't open file");
        return;
    }

    // Data dump
    char buffer[80];
    while(fscanf(input, "%s", buffer) != -1)
    {
        puts(buffer);
    }
    fclose(input);

    input = fopen("output.txt", "r");
    // read employee data now
    fscanf(input, "%s%s", buffer, name);
    fscanf(input, "%s%f", buffer, &hours);
    fscanf(input, "%s%f", buffer, &rate);

    printf("%s %f %f\n", name, hours, rate);
    fclose(input);

    dataFile = fopen("datafile.txt", "r");
    fscanf(input, "%s", name);
    fscanf(input, "%f", &hours);
    fscanf(input, "%f", &rate);
    fclose(dataFile);

    return 0;
}