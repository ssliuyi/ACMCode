#include<stdio.h>

int main()
{
    int n;
    double r1 = 0.0,r2 = 0.0;
    double x,y;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%lf%lf",&x,&y);
        r1=x*x+y*y;//家坐标
        for(int j=0;;j++)
        {
            r2 = j*100.0/3.14;
            if(r2 > r1)
            {
               printf("Property %d: This property will begin eroding in year %d.\n",i,j);
               break;
            }

        }
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
