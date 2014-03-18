#include<stdio.h>

int main()
{
    double x;
    double sum = 0;
    for(int i = 0;i < 12;i++)
    {
        scanf("%lf",&x);
        sum += x;
    }
    printf("$%.2lf",sum/12.0);
}
