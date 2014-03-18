#include<stdio.h>
__int64 n,m,i,top;
__int64 temp,ans,sum;
__int64 factor[20],mulfactor[20];

void find_factor(__int64 x)
{
	__int64 i;
	top=0;
	for(i=2;i*i<=x;i++)
		if(x%i==0)
		{
			while(x%i==0)
				x=x/i;
			top++;
			factor[top]=i;
		}
			if(x!=1)
				factor[++top]=x;
}

__int64 pow(__int64 x,__int64 y)
{
	__int64 temp;
	__int64 i;
	temp=1;
	for(i=1;i<=y;i++)
	{
		temp=temp*x;
	}
	return temp;
}

void find(__int64 loc,__int64 now,__int64 num)
{
	__int64 i;
	if(now==num)
	{
		__int64 temp=m;
		for(i=1;i<=num;i++)
			temp=temp/mulfactor[i];
		sum+=pow(temp,n);
	}
	else
		for(i=loc;i<=top;i++)
		{
			mulfactor[now+1]=factor[i];
			find(i+1,now+1,num);
		}
	}

int main()
{
	scanf("%I64d%I64d",&n,&m);
	find_factor(m);
	ans=pow(m,n);
	temp=1;
	for(i=1;i<=top;i++)
	{
		sum=0;
		find(1,0,i);
		temp*=-1;
		ans+=temp*sum;
	}
	printf("%I64d\n",ans);
	return 0;
}