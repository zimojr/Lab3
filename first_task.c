 /*
 1.Product of numbers

Create a program that calculates the product of the first 10 numbers (1…10), which is 10 factorial. You may use the given pseudo code. 
Put an extra line in the loop to print the value of the loop variable and that of the product as well in order to see how the product develops

Let the product be 1.
Let n be 10.
As long as n≥2
    Let product be product × n.
    Decrease n by 1.
End of repetition
Print the pruduct.*/

#include<stdio.h>

int main(){
    int num = 1;
    for (int i = 1; i <= 10; i++){
        
        num *= i;
    }
    printf("%d\n",num);
    return 0;
}
