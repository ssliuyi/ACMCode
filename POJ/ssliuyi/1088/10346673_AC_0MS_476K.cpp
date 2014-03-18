#include<iostream>

#include<cmath>

#include<cstring>

#include<cstdio>

#include<algorithm>

using namespace std;

 

 

struct dot//创建一个结构体存储每个点的信息

{

    int x;

    int y;

    int h;

};

dot line[20000]; //将每个点存入该结构体数组

int height[120][120]; //用于存储input

int len[120][120];  //dp数组，存储每个点的最优解

int cmp( const void *a ,const void *b) //快速排序的参考函数

{

 

    if((*(dot *)a).h>(*(dot *)b).h)

        return 1;

    else return -1;

 

}

int main ()

{

    int m,n;

    cin>>m>>n;

    int i,j;

    int flag=-1;

    int max=0;

    for(i=1;i<=m;i++)

    {

 

        for(j=1;j<=n;j++)

        {

            flag++;

            scanf("%d",&height[i][j]);

            line[flag].x=i;

            line[flag].y=j;

            line[flag].h=height[i][j];

        }

    } //这个双层循环用来完成数据收集的工作

    qsort(line,m*n,sizeof(line[0]),cmp); //对结构体的h参数进行排序

    for(i=0;i<m*n;i++)

    {

    if(height[line[i].x][line[i].y]<height[line[i].x][line[i].y+1]&&len[line[i].x][line[i].y]>=len[line[i].x][line[i].y+1])

        {

            len[line[i].x][line[i].y+1]=len[line[i].x][line[i].y]+1;

        }

    if(height[line[i].x][line[i].y]<height[line[i].x+1][line[i].y]&&len[line[i].x][line[i].y]>=len[line[i].x+1][line[i].y])

        {

            len[line[i].x+1][line[i].y]=len[line[i].x][line[i].y]+1;

        }

    if(height[line[i].x][line[i].y]<height[line[i].x][line[i].y-1]&&len[line[i].x][line[i].y]>=len[line[i].x][line[i].y-1])

        {

            len[line[i].x][line[i].y-1]=len[line[i].x][line[i].y]+1;

        }

        if (height[line[i].x][line[i].y]<height[line[i].x-1][line[i].y]&&len[line[i].x][line[i].y]>=len[line[i].x-1][line[i].y])

        {

            len[line[i].x-1][line[i].y]=len[line[i].x][line[i].y]+1;

        }

    } //动态规划过程

    for(i=1;i<=m;i++)

    {

        for(j=1;j<=n;j++)

        {

 

           

            if(len[i][j]>max)

                max=len[i][j];

        }

    } //遍历len数组，求出最大值

    cout<<max+1<<endl;// 因为初始值是0,所以最后要加一

    return 0;

}
