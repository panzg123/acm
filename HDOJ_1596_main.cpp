//2013-10-30 10:54:06	Accepted	1596	1484MS	9788K	1836 B	C++	���Ÿ���
#include <iostream>
#include <iomanip>
using namespace std;

/*==================================================*\
 | Dijkstra ����ʵ��O ��N^2 ��
| Dijkstra --- ����ʵ��( �ڴ˻����Ͽ�ֱ�Ӹ�ΪSTL ��Queueʵ��)
 | lowcost[] --- beg ����������������
| path[] -- begΪ��չ����������¼���׽��
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
            //����ļӷ����ܵ��������INF����ȡ̫��
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
