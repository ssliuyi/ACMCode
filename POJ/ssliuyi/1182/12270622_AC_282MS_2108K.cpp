#include<stdio.h>
#include<iostream>
#define MAX_N 200000
#define MAX_K 100001
using namespace std;

int par[MAX_N];
int rak[MAX_N];
int N,K;
int T[MAX_K],X[MAX_K],Y[MAX_K];

void init(int n)
{
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        rak[i]=0;
    }
}


int find(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    else
    {
        return par[x]=find(par[x]);
    }
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(rak[x]<rak[y])
    {
        par[x]=y;
    }
    else
    {
        par[y]=x;
        if(rak[x]==rak[y]) rak[x]++;
    }
}

bool same(int x,int y)
{
    return find(x)==find(y);
}

void solve()
{
    init(3*N);
    int ans=0;
    for(int i=0;i<K;i++)
    {
        int t=T[i];
        int x=X[i]-1,y=Y[i]-1;
        if(x<0||N<=x||y<0||N<=y)
        {
            ans++;
            continue;
        }
        if(t==1)
        {
            if(same(x,y+N)||same(x,y+2*N))
        	{
        	    ans++;
        	}
        	else
        	{
        	   unite(x,y);
        	   unite(x+N,y+N);
        	   unite(x+2*N,y+2*N);
        	}
        }
        else
        {
            if(same(x,y)||same(x,y+2*N))
            {
                ans++;
            }
            else
            {
               unite(x,y+N);
               unite(x+N,y+2*N);
               unite(x+2*N,y);
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++)
    {
        scanf("%d%d%d",&T[i],&X[i],&Y[i]);
    }
    solve();
    return 0;
}