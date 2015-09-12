//9435177	2013-10-28 15:14:23	Accepted	1879	843MS	332K	1461 B	C++	空信高手
#include <iostream>

using namespace std;
#define typec int
#define V 101
const typec inf=0x3f3f3f3f;
int vis[V];
int cost[V][V];
typec lowc[V];
/*==================================================*\
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
void Init()
{
    int i,j;
    for(i=0; i<V; i++)
        for(j=0; j<V; j++)
            cost[i][j]=10000000;
}

int main()
{
   // freopen("input.txt","r",stdin);
    int i,a,b,dis,flag,n;
    while(cin>>n&&n!=0)
    {
        Init();
        for(i=0;i<n*(n-1)/2;i++)
        {
            cin>>a>>b>>dis>>flag;
            if(flag==1) cost[a-1][b-1]=cost[b-1][a-1]=0;
            else cost[a-1][b-1]=cost[b-1][a-1]=dis;
        }
        cout<<prim(n)<<endl;
    }
    return 0;
}
