#include<stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
int K;
char ahph[]="AaBbCcDdEeFfGgHhIiGjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

bool compare(char a,char b)
{
	int x,y;
    for(int i=0;i<52;i++)
    {
        if(ahph[i]==a) x=i;
        if(ahph[i]==b) y=i;
    }
	return x<y;
}


int main()
{
   int n;
   char s[32];
   scanf("%d",&n);

   for(int i=0;i<n;i++)
   {
       scanf("%s",s);
       K=strlen(s);
       sort(s,s+strlen(s),compare);
       printf("%s\n",s);
       while(next_permutation(s,s+K,compare))
            printf("%s\n",s);

   }
   return 0;
}
