#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int findOperator(char *expr, int h, int t) {
    int lowPriority = -1;
    int highPriority = -1;

    int parenthesesCount = 0;
    for (int i = t; i >= h; i--) {
        if (expr[i] == ')')
            parenthesesCount++;
        else if (expr[i] == '(')
            parenthesesCount--;

        if (parenthesesCount == 0) {
            if ((expr[i] == '+' || expr[i] == '-') && lowPriority == -1)
                lowPriority = i;
            else if ((expr[i] == '*' || expr[i] == '/') && highPriority == -1)
                highPriority = i;
        }
    }

    return (highPriority != -1) ? highPriority : lowPriority;
}

float calculator(char *expr, int h, int t) {
    if (h > t)
        return 0;
    if (h == t)
        return expr[h] - '0';

    int index = findOperator(expr, h, t);
    if (index == -1)
        return atoi(expr + h);

    float first = calculator(expr, h, index - 1);
    float second = calculator(expr, index + 1, t);
    switch (expr[index]) {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        case '/': return first / second;
        default: return -1; 
    }
}

int main() {
    char expr[] = "(3+4)*5/6+7*8*(1+2-3)";

    printf("%f\n", calculator(expr, 0, 4));
    return 0;
}
