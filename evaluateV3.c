#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char expr[500], op_stack[500], tempOpr[500];
int op_top = -1, num_top = -1, mult = 1, num_stack[500];
void spush(char x)
{
    op_stack[++op_top] = x;
}

char spop()
{
    return op_stack[op_top--];
}

void ipush(int x)
{
    num_stack[++num_top] = x;
}

int ipop()
{
    return num_stack[num_top--];
}

int checkPrecedence(char x, char y)
{
    int a, b;
    switch (x)
    {
    case '-':
        a = 1;
        break;
    case '+':
        a = 2;
        break;
    case '*':
        a = 3;
        break;
    case '/':
        a = 4;
        break;
    case '^':
        a = 5;
        break;
    }
    switch (y)
    {
    case '-':
        b = 1;
        break;
    case '+':
        b = 2;
        break;
    case '*':
        b = 3;
        break;
    case '/':
        b = 4;
        break;
    case '^':
        b = 5;
        break;
    }
    if (a > b)
    {
        return 1;
    }
    return 0;
}

int calculate(int arg2, int arg1, char op)
{
    switch (op)
    {
    case '+':
        return arg1 + arg2;
    case '-':
        return arg1 - arg2;
    case '*':
        return arg1 * arg2;
    case '/':
        return arg1 / arg2;
    case '^':
        return pow(arg1, arg2);
    }
}

void evaluate()
{

    int tempIndex = 0;
    for (int i = 0; i < strlen(expr); i++)
    {

        if (expr[i] >= '0' && expr[i] <= '9')
        {
            tempOpr[tempIndex++] = expr[i];
        }
        else if (expr[i] == '(')
        {
            i++;
            int br_counter = 0;
            char num1, num2, opr;
            char br_temp[20];
            int temp_c = 0;
            while (expr[i] != ')')
            {
                printf("%c", expr[i]);
                ++i;
            }
            if (expr[i + 1] <= '0' || expr[i + 1] >= '9')
            {
                i++;
            }
        }
        else
        {
            ipush(atoi(tempOpr));
            memset(tempOpr, 0, sizeof tempOpr);
            tempIndex = 0;

            if (expr[i] == '\n')
                break;

            while (checkPrecedence(op_stack[op_top], expr[i]) != 0 && op_top > -1)
            {
                int arg2 = ipop();
                int arg1 = ipop();
                char op = spop();

                ipush(calculate(arg2, arg1, op));
            }
            spush(expr[i]);
        }
    }
    while (op_top != -1)
    {
        int arg2 = ipop();
        int arg1 = ipop();
        char op = spop();

        ipush(calculate(arg2, arg1, op));
    }
}

int main()
{
    printf("Enter expression : ");
    fgets(expr, 500, stdin);
    // expr[strlen(expr) - 1] = '?';

    evaluate();
    printf("\nResult = %d\n", num_stack[num_top]);

    return 0;
}