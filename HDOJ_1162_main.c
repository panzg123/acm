#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*=====================================*\
|Prim求MST
|INIT:const[][]耗费矩阵（inf为无穷大）
|CALL:prim(const,n);返回-1代表原图不连通
/*=====================================*/

#define typec double
#define V 105
typedef struct
{
    double x,y;
} Point;
Point pnt[V];
const typec inf=0x3f3f3f3f;
int vis[V];
typec lowc[V];
typec cost[V][V];
typec prim(int n)
{
    int i,j,p;
    typec minc,res=0;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(i=1; i<n; i++)
        lowc[i]=cost[0][i];
    for(i=1; i<n; i++)
    {
        minc=inf;
        p=-1;
        for(j=0; j<n; j++)
        {
            if(0==vis[j]&&minc>lowc[j])
            {
                minc=lowc[j];
                p=j;
            }
        }
        if(inf==minc)return -1;
        res+=minc;
        vis[p]=1;
        for(j=0; j<n; j++)
        {
            if(0==vis[j]&&lowc[j]>cost[p][j])
                lowc[j]=cost[p][j];
        }
    }
    return res;
}
void CaculateDistance(int num)
{
    int i,j;
    for(i=0; i<num; i++)
    {
        cost[i][i]=0;
        for(j=i+1; j<num; j++)
        {
            double result=sqrt((pnt[j].y-pnt[i].y)*(pnt[j].y-pnt[i].y)+(pnt[j].x-pnt[i].x)*(pnt[j].x-pnt[i].x));
            cost[i][j]=cost[j][i]=result;
        }
    }
}
int main()
{
    int num;
    int i=0;
    while(scanf("%d",&num)!=EOF)
    {
        memset(cost,10000,sizeof(cost));
        for(i=0; i<num; i++)
            scanf("%lf %lf",&pnt[i].x,&pnt[i].y);
        CaculateDistance(num);
        printf("%.2lf\n",prim(num));
    }

    return 0;
}
