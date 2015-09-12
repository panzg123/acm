//2013-10-30 10:54:06	Accepted	1596	1484MS	9788K	1836 B	C++	空信高手
#include <iostream>
#include <iomanip>
using namespace std;

/*==================================================*\
 | Dijkstra 数组实现O （N^2 ）
| Dijkstra --- 数组实现( 在此基础上可直接改为STL 的Queue实现)
 | lowcost[] --- beg 到其他点的最近距离
| path[] -- beg为根展开的树，记录父亲结点
\*==================================================*/
const int N=1100;
int path[N],vis[N];
double cost[N][N],lowcost[N];
void Dijkstra(int n,int beg)
{
    int i,j;
    double max;
    memset(vis,0,sizeof(vis));
    vis[beg]=1;
    for(i=0; i<n; i++)
    {
        lowcost[i]=cost[beg][i];
        path[i]=beg;
    }
    lowcost[beg]=0;
    path[beg]=-1;
    int pre=beg;
    for(i=1; i<n; i++)
    {
        max=0;
        for(j=0; j<n; j++)
            //下面的加法可能导致溢出，INF不能取太大
            if(vis[j]==0&&lowcost[pre]*cost[pre][j]>lowcost[j])
            {
                lowcost[j]=lowcost[pre]*cost[pre][j];
                path[j]=pre;
            }
        for(j=0; j<n; j++)
            if(vis[j]==0&&lowcost[j]>max)
            {
                max=lowcost[j];
                pre=j;
            }
        vis[pre]=1;
    }
}

int main()
{
 //   freopen("input.txt","r",stdin);
    int n,m,i,j,a,b;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(cost,0,sizeof(cost));
        memset(lowcost,0,sizeof(lowcost));
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>cost[i][j];
        cin>>m;
        while(m--)
        {
            cin>>a>>b;
            Dijkstra(n,a-1);
            if(lowcost[b-1]!=0)cout<<setiosflags(ios::fixed)<<setprecision(3)<<lowcost[b-1]<<endl;
            else cout<<"What a pity!"<<endl;
        }
    }
    return 1;
}
