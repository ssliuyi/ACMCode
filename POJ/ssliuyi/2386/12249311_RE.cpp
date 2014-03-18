#include <iostream>
#include <stdio.h>
#define MAX_N 110
#define MAX_M 110
using namespace std;

int N,M;
char field[MAX_N][MAX_M+1];

void dfs(int x,int y)
{
    field[x][y]='.';
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            int xn=x+i;
            int yn=y+j;
            if(xn>=0&&xn<N&&yn>=0&&yn<M&&field[xn][yn]=='W') dfs(xn,yn);
        }
    }
}

void solve()
{
    int result=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(field[i][j]=='W')
            {
                dfs(i,j);
                result++;
            }
          //  printf("%c",field[i][j]);
        }
       // printf("\n");
    }
    printf("%d\n",result);
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%c",&field[i][j]);
        }
        scanf("%c");
    }
    solve();
}
