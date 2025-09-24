/*
John Wallis, British mathematician developed the following expression to compute the constant π:

π   2·2   4·4   6·6   8·8
─ = ─── · ─── · ─── · ─── · …
2   1·3   3·5   5·7   7·9

Identify the repeating pattern in the formula, and write a program to evaluate it up to the first n factors (n is obtained f0rom the user). Test the program with n=10, n=100 and n=1000 settings!
*/

#include<stdio.h>

int main(){
    double pi = 1;
    int n;
    printf("Resolution: ");
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2){
        pi *= (i*i)/((i+1)*(i-1.0));
    }
    pi *= 2;
    printf("Pi is %f\n", pi);
    return 0;
}
