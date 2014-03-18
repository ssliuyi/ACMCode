#include<stdio.h>
#include<iostream>
#include <algorithm>
using namespace std;
int t;//测试组数
int k;//字母数
int p;//每个字母出现次数
int mark[32][32]={0};
struct RECT
{
    int top;
    int bottom;
    int left;
    int right;
    int rank;
};
RECT rect[32];
void fun()
{
    for(int i=0;i<32;i++)
    {
        rect[i].top=1000001;
        rect[i].bottom=0;
        rect[i].right=0;
        rect[i].left=1000001;
        rect[i].rank=i;
    }
}
void Search(int k,int p)//对于字母k 循环p次
{
    int x;int y;
    for(int a=0;a<k;a++)
    {
        for(int i=0;i<p;i++)
        {
            scanf("%d%d",&x,&y);
            if(rect[a].top>y) rect[a].top=y;
            if(rect[a].bottom<y) rect[a].bottom=y;
            if(rect[a].left>x) rect[a].left=x;
            if(rect[a].right<x) rect[a].right=x;
        }
    }

}

bool compare1(RECT a,RECT b)
{
    return a.top<b.top;
}

bool compare2(RECT a,RECT b)
{
    return a.left<b.left;
}

bool judge()//对于字母k 循环p次
{
    int i;
    sort(rect,rect+32,compare1);
    for(i=0;i<k-1;i++)
    {
        if(rect[i].bottom-rect[i+1].top>=0) {mark[rect[i].rank][rect[i+1].rank]=1; mark[rect[i+1].rank][rect[i].rank]=1;}
    }
    sort(rect,rect+32,compare2);
    for(i=0;i<k-1;i++)
    {
        if(rect[i].right-rect[i+1].left>=0&&(mark[rect[i].rank][rect[i+1].rank]==1||mark[rect[i+1].rank][rect[i].rank]==1)) return false;
    }
    return true;
}


int main()
{
    fun();
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&k,&p);
        Search(k,p);
        if(judge())
            printf("YES\n");
        else
            printf("NO\n");
    }
}
