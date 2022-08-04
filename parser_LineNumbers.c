//NUMBERED TEXT
//input: *.txt file
//output: numbered_*.txt 

#include <stdio.h>
#include <string.h>


int main() {
 
    char fileNAME[100];
    puts("filename?");
    scanf("%s", fileNAME);
    FILE * addNUMB = fopen(fileNAME, "r");
    if (addNUMB == NULL)
    {
        puts("error opening!");
        return 2;
    }
  
    char oFile[100] = "numbered_";
    FILE *linesADDED = fopen(strcat(oFile, fileNAME), "w");
    
    int lineNUM = 1;
    char lineTEXT[200];
    do{
        fgets(lineTEXT, 200, addNUMB);
        if (feof(addNUMB) == 1)
            break;
        fprintf(linesADDED, "%d) %s", lineNUM++, lineTEXT);
    }while(1);
    
    fclose(addNUMB);
    fclose(linesADDED);
    return 0;
  
}