#include<stdio.h>

int f(double longth)
{
    double sum = 0;
    for(int a = 1;;a++)
    {
        sum += 1/double((a+1));
        if(sum>longth)
        {
            return a;
        }
    }
}

int main()
{
	int s;
    while(1)
    {
        double x;
        scanf("%lf",&x);
		if(x==0.00)
			break;
		s = f(x);
        printf("%d card(s)\n",s);
    }
    return 0;
}
