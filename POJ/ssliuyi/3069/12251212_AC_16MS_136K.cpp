#include <cstdio>
#include <cstddef>
#include <algorithm>
using namespace std;

int pos[1010];

int main()
{
   //freopen("in.txt","r",stdin);
   int r,n;
   while(~scanf("%d%d",&r,&n)&&(r+n!=-2))
   {
       for(size_t i=0;i!=(size_t)n;i++) scanf("%d",&pos[i]);

       sort(pos,pos+n);

       size_t count=0;

       for(size_t i=0;i<n;i++)
       {
           size_t j=i,t;
           while(pos[j]<=pos[i]+r) j++;
           j--;
           for(t=j;pos[t]<=r+pos[j];t++);
           i=t-1;

           count++;
       }
       printf("%d\n",count);
   }
   return 0;
}