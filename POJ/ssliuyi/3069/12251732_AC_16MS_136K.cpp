#define MAX_N 1001
#include<stdio.h>
#include<algorithm>
using namespace std;

static int R;
int N;
int a[MAX_N];

void solve()
{
	int res=0;
	int i=0;
	sort(a,a+N);
	while(i<N)
	{
		int s=a[i++];
		while(i<N && a[i]<=s+R) i++;
		int p = a[i-1];
		while(i<N && a[i]<=p+R) i++;
		res++;
	}

	printf("%d\n",res);
}

int main()
{
		while(scanf("%d%d",&R,&N)!=EOF)
		{
			if(R==-1&&N==-1) return 0;
			for(int i=0;i<N;i++)
			{
				scanf("%d",&a[i]);
			}
			solve();
		}
}
