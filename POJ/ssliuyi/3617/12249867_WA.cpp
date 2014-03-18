#include <stdio.h>
#define MAX_N 2000
int N;
char S[MAX_N+1];

void solve()
{
	int a=0;
	int b=N-1;
	while(a<=b)
	{
		bool left=false;
		for(int i=0;a+i<=b;i++)
		{
			if(S[a+i]<S[b-i])
			{
				left=true;
				break;
			}
			else
			{
				left=false;
				break;
			}
		}
		if(left) putchar(S[a++]);
		else putchar(S[b--]);
	}
	putchar('\n');
}

int main()
{
	scanf("%d",&N);
	getchar();
	for(int i=0;i<N;i++)
	{
		scanf("%c",&S[i]);
		getchar();
	}
	solve();
}