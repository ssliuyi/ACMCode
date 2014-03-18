#include <stdio.h>
#define MAX_N 2000
int N;
char S[MAX_N+1];
char R[MAX_N+1];
void solve()
{
	int k=0;
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
			else if(S[a+i]>S[b-i])
			{
				left=false;
				break;
			}
		}
		if(left) R[k++]=S[a++];
		else R[k++]=S[b--];
	}
	k=0;
	while(k<N)
	{
		if(k>=80 && k%80==0)
		{
			printf("\n");
		}
		printf("%c",R[k++]);
	}
	putchar('\n');
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		getchar();		
		scanf("%c",&S[i]);
	}
	solve();
}