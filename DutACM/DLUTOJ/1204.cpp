#include <iostream>
#include <stdio.h>
using namespace std;

int N;
int solve()
{
    int res=0;
    int r=0,v=0;
    res += N / 16 * 9;
    r = N % 16;
    res += r / 8 * 3;
    r = r %  8;
    res += r/4;
    return res;
}
int main()
{
    while(scanf("%d",&N) != EOF )
    {
        int res = solve();
        printf("%d\n",res);
    }
    return 0;
}
