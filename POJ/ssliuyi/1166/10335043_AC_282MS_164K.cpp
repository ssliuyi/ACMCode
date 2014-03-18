#include<stdio.h>

int operate[9][9]={                                                                                    //记录每一种口令对每一个钟表的影响
    {1,1,0,1,1,0,0,0,0},
    {1,1,1,0,0,0,0,0,0},
    {0,1,1,0,1,1,0,0,0},
    {1,0,0,1,0,0,1,0,0},
    {0,1,0,1,1,1,0,1,0},
    {0,0,1,0,0,1,0,0,1},
    {0,0,0,1,1,0,1,1,0},
    {0,0,0,0,0,0,1,1,1},
    {0,0,0,0,1,1,0,1,1}
};//操作方法

int num[9];//口令i的执行次数
bool finish=false;//标记是否完成
int ans[9];//钟表情况
int temp[9];

bool p()//操作函数
{
    for(int m=0;m<9;m++)    temp[m]=ans[m];

    for(int i=0;i<9;i++)//对于每个num,每一种口令
    {
        for(int j=0;j<num[i];j++)//执行num[i}次
        {
            for(int k=0;k<9;k++)//对于每个钟表
            {
                temp[k] += operate[i][k];
                temp[k] %= 4;
            }
        }
    }
    for(int n=0;n<9;n++)//检测是否操作成功
    {
        if(temp[n] != 0) return false;
    }
    return true;
}

void Output()
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<num[i];j++)
            printf("%d ",i+1);
        printf("\n");
}

void DFS(int opeartion)//从口令opeartion开始搜索
{
    int i;
    if(p())
    {
        finish=true;
        Output();
        return;
    }
    if(opeartion >= 9)
        return;
    for(i=0;i<4;i++)
    {
        num[opeartion]=i;
        DFS(opeartion+1);
        if(finish)
            return;
    }

}

int main()
{
    int i;
    for(i=0;i<9;i++)
        scanf("%d",&ans[i]);
    finish=false;
    DFS(0);
    return 0;
}
