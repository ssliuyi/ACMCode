#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

char array[10000001];//存号码
char map[26] =
{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','Q','7','7','8','8','8','9','9','9','Z'};
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
		if(array[i]>1)
		{
			printf("%03d-%04d %d\n",i/10000,i%10000,array[i]);//精髓啊，节省不少代码
			judge=1;
		}
    }
	if(judge==0)
	{
		printf("No duplicates.\n");
	}
	system("pause");
    return 0;
}
