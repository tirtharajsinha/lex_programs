#include <stdio.h>
#include <string.h>

int main()
{
    char var[500];
    printf("Enter a comment\n");
    fgets(var, 500, stdin);

    if (strlen(var) > 2 && var[0] == '/' && var[1] == '/')
    {
        printf("This is valid comment.\n");
    }
    else if (strlen(var) > 5 && var[0] == '/' && var[1] == '*' && var[strlen(var) - 3] == '*' && var[strlen(var) - 2] == '/')
    {
        printf("This is valid comment.\n");
    }
    else
    {
        printf("This is not a valid comment.\n");
    }

    return 0;
}