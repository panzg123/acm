#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int Edge[101][101];
    int n,m;
    int i,j,k;
    int flag[101];
    int Min=10000;
    int Point=0,count;
    int Sum=0,temp1,temp2,temp3;
    while(scanf("%d %d",&n,&m)&&n!=0)
    {
        Sum=0;
        Point=0;
        memset(Edge,10000,sizeof(Edge));
        memset(flag,0,sizeof(flag));
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&temp1,&temp2,&temp3);
            Edge[temp1-1][temp2-1]=temp3;
        }
        flag[0]=1;
        count=m-1;
        while(count--)
        {
            Min=10000;
            for(i=0; i<m; i++)
            {
                for(j=0; j<m; j++)
                {
                    if(flag[i]==1&&flag[j]==0)
                    {
                        if(Edge[i][j]<Min)
                        {
                            Min=Edge[i][j];
                            Point=j;
                        }
                    }
                }
            }
            flag[Point]=1;
            Sum+=Min;
        }
        if(Sum<10000)
            printf("%d\n",Sum);
        else
            printf("?\n");
    }
    return 0;
}
