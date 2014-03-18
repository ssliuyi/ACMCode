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
        rect[i].top=2000001;
        rect[i].bottom=-1;
        rect[i].right=-1;
        rect[i].left=2000001;
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


bool judge()//对于字母k 循环p次
{
    for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			if((i!=j)&&(rect[i].top>rect[j].bottom||rect[i].bottom<rect[j].top||rect[i].left>rect[j].right||rect[i].right<rect[j].left))
				continue;
			else
				return 0;
		}
	}
	return 1;
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
