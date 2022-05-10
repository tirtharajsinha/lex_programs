#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char expr[500] = {'1', '0', '/', '5', '*', '2', '+', '3', '?'}, op_stack[500], tempOpr[500];
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
    // printf("%d, ", x);
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
    // printf("cal %d%c%d\n", arg1, op, arg2);
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

void infixToPostfix()
{

    int tempIndex = 0;
    for (int i = 0; i < strlen(expr); i++)
    {
        // printf("%c |", expr[i]);
        if (expr[i] >= '0' && expr[i] <= '9')
        {
            tempOpr[tempIndex++] = expr[i];
            // printf("%s\n", tempOpr);
        }
        else if (expr[i] == '?')
        {
            ipush(atoi(tempOpr));
            // printf("%d ,", atoi(tempOpr));
            memset(tempOpr, 0, sizeof tempOpr);
            // printf("%s |", tempOpr);
            tempIndex = 0;
            break;
        }
        else
        {
            ipush(atoi(tempOpr));

            memset(tempOpr, 0, sizeof tempOpr);

            tempIndex = 0;

            while (checkPrecedence(op_stack[op_top], expr[i]) != 0 && op_top > -1)
            {
                int arg2 = ipop();
                int arg1 = ipop();
                char op = spop();

                ipush(calculate(arg2, arg1, op));
            }
            spush(expr[i]);

            //     if (op_top > -1)
            //     {

            //         if (checkPrecedence(op_stack[op_top], expr[i]) == 0)
            //         {

            //             spush(expr[i]);
            //         }

            //         else
            //         {
            //             int arg2 = ipop();
            //             int arg1 = ipop();
            //             char op = spop();

            //             ipush(calculate(arg2, arg1, op));
            //             while (checkPrecedence(op_stack[op_top], expr[i]) != 0 && op_top > -1)
            //             {
            //                 int arg2 = ipop();
            //                 int arg1 = ipop();
            //                 char op = spop();

            //                 ipush(calculate(arg2, arg1, op));
            //             }
            //             spush(expr[i]);
            //         }
            //     }
            //     else if (op_top == -1)
            //     {
            //         spush(expr[i]);
            //     }
        }
    }
    while (op_top != -1)
    {
        int arg2 = ipop();
        int arg1 = ipop();
        char op = spop();
        // printf("%d", calculate(arg2, arg1, op));
        ipush(calculate(arg2, arg1, op));
    }
}

int main()
{
    printf("Enter expression : ");
    fgets(expr, 500, stdin);
    expr[strlen(expr) - 1] = '?';
    // printf("%s|", expr);

    infixToPostfix();
    printf("\nresult = %d\n", num_stack[num_top]);
    // for (int i = 0; i <= num_top; i++)
    // {
    //     printf("%d |", num_stack[i]);
    // }
    return 0;
}