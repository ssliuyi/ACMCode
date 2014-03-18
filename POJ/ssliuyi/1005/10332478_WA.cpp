#include<stdio.h>

int main()
{
    int n,j;
    double r1 = 0.0,r2 = 0.0;
    double x,y;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%lf%lf",&x,&y);
        r1=x*x+y*y;//家坐标
        j=int(r1*3.1415926/100+1);
        printf("Property %d: This property will begin eroding in year %d.\n",i,j);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
