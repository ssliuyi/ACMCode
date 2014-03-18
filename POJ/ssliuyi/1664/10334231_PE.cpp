#include<stdio.h>

int P(int m,int n)
{
    if(m==0||n==1)
        return 1;
    else if(m < n)
        return P(m,m);
    else
        return P(m,n - 1)+P(m - n,n);
}

int main()
{
    int n;
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d",P(a,b));
    }
    return 0;
}
