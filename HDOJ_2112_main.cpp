//2013-10-31 14:17:50	Accepted	2112	1921MS	408K	2388 B	C++	空信高手
#include <iostream>
#include <string>
#include <map>

using namespace std;
#define N 160
#define INF 0x3F3F3F3F
map<string,int> map1;
int f,cost[N][N];

int path[N],vis[N];

/*==================================================*\
 | Dijkstra 数组实现O （N^2 ）
| Dijkstra --- 数组实现( 在此基础上可直接改为STL 的Queue实现)
 | lowcost[] --- beg 到其他点的最近距离
| path[] -- beg为根展开的树，记录父亲结点
\*==================================================*/

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
            //下面的加法可能导致溢出，INF不能取太大
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

int Judge(string str)
{
    pair<map<string,int>::iterator,bool> iter;
    iter = map1.insert(make_pair(str,++f));
    if(iter.second) return f;
    else
    {
        --f;
        return map1[str];
    }
}

int main()
{
    int n,i,j,k,a,b;
    string firstName,lastName;
    int dis;
   // freopen("input.txt","r",stdin);
    while(cin>>n&&n!=-1)
    {
        map1.clear();
        int lowcost[N];
        Init();
        f=0;
        cin>>firstName>>lastName;
        a=Judge(firstName);b=Judge(lastName);//a是起点，b是终点
        for(i=0; i<n; i++)
        {
            cin>>firstName>>lastName>>dis;
            j=Judge(firstName);k=Judge(lastName);
            cost[j-1][k-1]=cost[k-1][j-1]=dis;
        }
        Dijkstra(lowcost,f,a-1);
        if(lowcost[b-1]<INF)cout<<lowcost[b-1]<<endl;
        else cout<<"-1"<<endl;
//        for(map<string,int>::iterator it=map1.begin(); it!=map1.end(); it++)
//            cout<<it->first<<"  "<<it->second<<endl;
    }
    return 0;
}
