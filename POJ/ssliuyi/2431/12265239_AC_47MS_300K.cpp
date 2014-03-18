#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define MAX_N 10001
using namespace std;
int L,P,N;
struct Stop
{
    int dis;
    int fuel;
};

Stop A[MAX_N];

bool compdis(Stop a,Stop b)
{
    return a.dis<b.dis;
}

void solve()
{
	sort(A,A+N,compdis);
	A[N].dis=L;
        A[N].fuel=0;
	N++;

	priority_queue<int> que;

	int ans=0,pos=0,tank=P;
	for(int i=0;i<N;i++)
	{
		int d=A[i].dis-pos;
		while(tank-d<0)
		{
			if(que.empty())
			{
				puts("-1");
				return;
			}
			tank+=que.top();
			que.pop();
			ans++;
		}
		tank-=d;
		pos=A[i].dis;
		que.push(A[i].fuel);
    }
	printf("%d\n",ans);
}

int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&A[i].dis,&A[i].fuel);
    }
    scanf("%d%d",&L,&P);
    for(int i=0;i<N;i++)
    {
        A[i].dis=L-A[i].dis;
    }
    solve();
    return 0;
}