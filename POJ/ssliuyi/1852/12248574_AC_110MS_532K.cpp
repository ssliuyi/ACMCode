#include <iostream>
#include <stdio.h>
#define MAX_N 999999
using namespace std;

int L,n;
int x[MAX_N];

void solve()
{
    int minT=0;
    for(int i=0;i<n;i++)
    {
        minT=max(minT,min(x[i],L-x[i]));
    }

    int maxT=0;
    for(int i=0;i<n;i++)
    {
        maxT=max(maxT,max(x[i],L-x[i]));
    }
    printf("%d %d\n",minT,maxT);
}
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&L);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        solve();
    }
}
