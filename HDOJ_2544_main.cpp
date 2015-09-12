//2013-10-30 10:01:25	Accepted	2544	15MS	340K	1824 B	C++	���Ÿ���
#include <iostream>
using namespace std;

/*==================================================*\
 | Dijkstra ����ʵ��O ��N^2 ��
| Dijkstra --- ����ʵ��( �ڴ˻����Ͽ�ֱ�Ӹ�ΪSTL ��Queueʵ��)
 | lowcost[] --- beg ����������������
| path[] -- begΪ��չ����������¼���׽��
\*==================================================*/
#define INF 0x3F3F3F3F;
const int N=110;
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
 //  freopen("input.txt","r",stdin);
    int n,m,i,a,b,dis;
    while(cin>>n>>m&&!(n==0&&m==0))
    {
        Init();
        int lowcost[N];
        for(i=0; i<m; i++)
        {
            cin>>a>>b>>dis;
            if(cost[a-1][b-1]>dis)
                cost[a-1][b-1]=cost[b-1][a-1]=dis;
        }
        Dijkstra(lowcost,n,0);
        cout<<lowcost[n-1]<<endl;
//        if( lowcost[n-1] < 0x3F3F3F3F ) cout<<lowcost[n-1]<<endl;
//        else cout<<"-1"<<endl;
    }
    return 1;
}
