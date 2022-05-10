#include <stdio.h>
#include <string.h>

int main()
{
    char var[500];
    printf("Enter a name of a variable : ");
    scanf("%s", var);

    if (!((var[0] >= 'a' && var[0] <= 'z') || (var[0] >= 'A' && var[0] <= 'Z') || var[0] == '_'))
    {
        printf("%s is not valid variable.\n", var);
        return 0;
    }

    for (int i = 1; i < strlen(var); i++)
    {
        if (!((var[i] >= 'a' && var[i] <= 'z') || (var[i] >= 'A' && var[i] <= 'Z') || var[i] == '_' || (var[i] >= '0' && var[i] <= '9')))
        {

            printf("%s is not valid variable.\n", var);
            return 0;
        }
    }

    printf("%s is valid variable.\n", var);

    return 0;
}