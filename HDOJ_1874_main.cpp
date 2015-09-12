//2013-10-28 16:06:36	Accepted	1874	0MS	472K	1790 B	C++	���Ÿ���
#include <iostream>
using namespace std;

/*==================================================*\
 | Dijkstra ����ʵ��O ��N^2 ��
| Dijkstra --- ����ʵ��( �ڴ˻����Ͽ�ֱ�Ӹ�ΪSTL ��Queueʵ��)
 | lowcost[] --- beg ����������������
| path[] -- begΪ��չ����������¼���׽��
\*==================================================*/
#define INF 0x3F3F3F3F;
const int N=210;
int path[N],vis[N];
int cost[N][N];
void Dijkstra(int lowcost[N],int n,int beg)
{
    int i,j,min;
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
        min=INF;
        for(j=0; j<n; j++)
            //����ļӷ����ܵ��������INF����ȡ̫��
            if(vis[j]==0&&lowcost[pre]+cost[pre][j]<lowcost[j])
            {
                lowcost[j]=lowcost[pre]+cost[pre][j];
                path[j]=pre;
            }
        for(j=0; j<n; j++)
            if(vis[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                pre=j;
            }
        vis[pre]=1;
    }
}
void Init()
{
    int i,j;
    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            cost[i][j]=INF;
}

int main()
{
  // freopen("input.txt","r",stdin);
    int n,m,i,a,b,dis;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        Init();
        int lowcost[N];
        for(i=0; i<m; i++)
        {
            cin>>a>>b>>dis;
            if(cost[a][b]>dis)
                cost[a][b]=cost[b][a]=dis;
        }
        cin>>a>>b;
        Dijkstra(lowcost,n,a);
        if( lowcost[b] < 0x3F3F3F3F ) cout<<lowcost[b]<<endl;
        else cout<<"-1"<<endl;
    }
    return 1;
}
