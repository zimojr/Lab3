/*Leibniz found the expression below to approximate π. The more terms are taken into account, the more accurate the approximation is. Write a program to approximate π with this method!

π       1   1   1
─ = 1 - ─ + ─ - ─ + …
4       3   5   7

There are several potential pitfalls in this task. If the output of the program is not correct, run the debugger, and follow the program execution and the evolution of the variables step-by-step!

Hint: note that the additions and subtractions are alternating. It might be worth to compute the sum such that two terms are computed in each iteration of the loop.
This way checking the loop variable whether it is even or odd is not necessary.

Important: use real data types (float or double), since the result is not integer. In C, if two integer numbers are divided, the result will be integer as well.
Hence, 1/3, in C, gives 0. However, 1.0/3 gives 0.333333 that is the correct value. We are going to discuss this issue at a later lecture.*/

#include <stdio.h>

int main()
{
    double pi = 0;
    int res = 100000000;
    for (int i = 1; i <= res * 4; i += 4)
    {
        pi += 1.0 / i;
        pi -= 1 / (i + 2.0);
    }
    pi *= 4;
    printf("%f", pi);
    return 0;
}
