#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
long min=10000000,max=0;
int array[10000001]={0};//存号码
char map[26] =
{'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','Q','7','7','8','8','8','9','9','9','Z'};
void p(char * x)//取消-
{
    char temp[8];
    int k = 0;
    for(int j=0;j<strlen(x);j++)
    {
        if(x[j]>='A'&&x[j]<='Z')
            temp[k++] = map[x[j]-'A'];
        else if(x[j]>='0'&&x[j]<='9')
            temp[k++] = x[j];
        else
            continue;
    }
    temp[k]='\0';

	int c = atoi(temp);
	if(c>max) max=c;
	if(c<min) min=c;
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
    }
    
    for(int i=min;i<=max;i++)
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

    return 0;
}
