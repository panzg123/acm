
#include <iostream>

using namespace std;
#define typec int
#define V 101
const typec inf=0x3f3f3f3f;
int vis[V];
typec lowc[V],cost[V][V];
/*=================================================*\
 | Prim求MST
 | INIT: cost[][]耗费矩阵(inf为无穷大);
 | CALL: prim(cost, n); 返回-1代表原图不连通;
\*==================================================*/
typec prim(int n)
{
    int i,j,p;
    typec minc,res=0;
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(i=1; i<n; i++) lowc[i]=cost[0][i];
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
        if(inf==minc) return -1;
        res+=minc;
        vis[p]=1;
        for(j=0; j<n; j++)
            if(0==vis[j]&&lowc[j]>cost[p][j])lowc[j]=cost[p][j];
    }
    return res;
}


int main()
{
 //   freopen("input.txt","r",stdin);
    int n,m,i,j,u,v;
    while(cin>>n&&n!=0)
    {
        memset(cost,inf,sizeof(cost));
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                cin>>cost[i][j];
        cin>>m;
        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            cost[u-1][v-1]=cost[v-1][u-1]=0;
        }
        cout << prim(n) << endl;
    }
    return 0;
}
