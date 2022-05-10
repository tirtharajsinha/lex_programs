#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *source, *target;

void single_line()
{
    char ch = fgetc(source);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            return;
        }
        ch = fgetc(source);
    }
}

void multi_line()
{
    char ch = fgetc(source);
    while (ch != EOF)
    {
        if (ch == '*')
        {
            ch = fgetc(source);
            if (ch == '/')
            {
                return;
            }
        }
        ch = fgetc(source);
    }
}

int main()
{
    char sourcefilename[100] = "code.c";
    char targetfilename[100] = "newcode.c";

    // printf("Enter Source file name : ");
    // scanf("%s", sourcefilename);
    // printf("Enter target file name : ");
    // scanf("%s", targetfilename);

    source = fopen(sourcefilename, "r");
    target = fopen(targetfilename, "w");

    char ch = fgetc(source);
    while (ch != EOF)

    {
        if (ch == '/')
        {
            char temp = ch;
            ch = fgetc(source);
            if (ch == '/')
            {
                single_line();
            }
            else if (ch == '*')
            {
                multi_line();
            }
            else
            {
                fputc(temp, target);
                fputc(ch, target);
                printf("%c%c", temp, ch);
            }
        }
        else
        {
            fputc(ch, target);
            printf("%c", ch);
        }
        ch = fgetc(source);
    }

    fclose(source);
    fclose(target);

    return 0;
}