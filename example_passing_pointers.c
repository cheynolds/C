#include <stdio.h>

char loadvars(int *val1, int *val2);

int main()
{
    int val1;
    int val2;
    char val3;
    //call function val3, passing addresses of val1 and val2
    val3 = loadvars(&val1, &val2);
    printf("%d %d %c", val1, val2, val3);
    return 0;
}

char loadvars(int *val1, int *val2)
{
    char val3;
    printf("Enter two integars: ");
    scanf("%d%d", val1, val2);
    printf("Enter a character: ");
    //scanf("%c ",&val3);
    //stores character replacing return key as final value of val3
    scanf("%c%c", &val3, &val3);
    return val3;
}
