#include <stdio.h>

long factorial(int n)
{
        if ( n==0 || n==1 ) {
            return 1;
        } else {
            return n * factorial(n-1);//递归调用
        }
    }   

int main()
{
    int num;

    scanf("%d",&num);
    
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %ld\n", num, factorial(num));
    }

    return 0;
}