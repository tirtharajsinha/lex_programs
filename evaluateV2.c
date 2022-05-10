#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char expr[500], op_stack[500], tempOpr[500];
int op_top = -1, num_top = -1, num_stack[500];

void spush(char x) // For pushing operator in operator stack
{
    op_stack[++op_top] = x;
}

char spop() // For popping operator from operator stack
{
    return op_stack[op_top--];
}

void ipush(int x) // For pushing number in number stack
{
    num_stack[++num_top] = x;
}

int ipop() // For popping number from number stack
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
        return 1; // returns 1 when operator in stack has higher precedence than the current scanned operator from expression
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
        if (expr[i] >= '0' && expr[i] <= '9') // If scanned character is a digit, keep on storing in a string. Required for multiple digits
        {
            tempOpr[tempIndex++] = expr[i];
        }
        else if (expr[i] == '(') // activate only if bracket found
        {
            i++;
            while (expr[i] != ')')
            {
                printf("%c", expr[i]);
                ++i;
            }
            if (expr[i + 1] <= '0' || expr[i + 1] >= '9') // ignore this part
            {
                i++;
            }
        }
        else
        {
            ipush(atoi(tempOpr));               // Once an operand comes after the numbers, push the stored number into num_stack
            memset(tempOpr, 0, sizeof tempOpr); // Reset the string
            tempIndex = 0;

            if (expr[i] == '\n')
                break; // For picking the last character

            while (checkPrecedence(op_stack[op_top], expr[i]) != 0 && op_top > -1) // Keep on calculating till current operator has higher precedence than the operator in stack
            {
                int arg2 = ipop();
                int arg1 = ipop();
                char op = spop();
                ipush(calculate(arg2, arg1, op)); // Calculating the expression
            }
            spush(expr[i]); // If there is no operator in stack, or pushing the operator if it has higher precendence than om the stack
        }
    }
    while (op_top != -1) // If there is any operator remaining in the stack, pop them and calculate
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
    evaluate();
    printf("Result = %d\n", num_stack[num_top]);
    return 0;
}