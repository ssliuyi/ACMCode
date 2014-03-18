#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>


char array[10000001];//存号码
char map[] = "2223334445556667777888999";

void p(char * x)//取消-
{
	char *pp=x;
    char temp[8];
    int i = 0;
    while(* pp != '\0' )
    {
        if(*pp != '-'&& *pp != 'Q' && *pp != 'Z' )  temp[i++]=*pp;
        pp++;
    }
    temp[i]='\0';
	strcpy(x,temp);

}


void f(char * x)//转化为数字
{
    while(*x != '\0')
    {
        if(*x>'9'||*x<'0')
        {
			*x=map[*x-'A'];
        }
        x++;
    }
}

void r(char * x)//记录
{
   int c=atoi(x);
	array[c]++;
}

int main()
{
	bool judge=0;
    int n=0;
    scanf("%d",&n);
    char temp[30];
    for(int k=0;k<n;k++)
    {
        scanf("%s",temp);
        p(temp);
        f(temp);
        r(temp);
    }
    for(int i=0;i<10000001;i++)
    {
		
		int ss=i;
		if(array[i]>1)
		{
			for(int j=0;j<7;j++)
			{
				temp[j]=ss%10+'0';
				ss/=10;
			}
			printf("%c%c%c-%c%c%c%c %d\n",temp[6],temp[5],temp[4],temp[3],temp[2],temp[1],temp[0],array[i]);
			judge=1;
		}
    }
	if(judge==0)
	{
		printf("No duplicates.\n");
	}
    return 0;
}
