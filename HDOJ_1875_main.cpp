//9403289	2013-10-24 17:00:49	Accepted	1875	62MS	376K	2205 B	C++	空信高手
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define typec double
#define V 101
const typec inf=10000000;
int vis[V];
typec lowc[V],cost[V][V];
typedef struct
{
    int x;
    int y;
} POINT;
POINT pnts[V];
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

double calDis(POINT a,POINT b)
{
    return sqrt(double((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
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
    int n,i,j;
    while(cin>>n&&n!=0)
    {
        while(n--)
        {
            int m;
            double Sum=0;
            cin>>m;
            Init();
            //memset(cost,inf,sizeof(cost));

            for(i=0; i<m; i++)
                cin>>pnts[i].x>>pnts[i].y;
            for(i=0; i<m; i++)
                for(j=0; j<m; j++)
                {
                    if(calDis(pnts[i],pnts[j])<=1000.000001&&calDis(pnts[i],pnts[j])>=10.000000)
                        cost[i][j]=calDis(pnts[i],pnts[j]);
                }
//            if(!flag) cout<<setiosflags(ios::fixed)<<setprecision(1)<<prim(m)*100<<endl;
//            else cout<<"oh!"<<endl;
            Sum=prim(m);
            if(Sum<0) cout<<"oh!"<<endl;
            else cout<<setiosflags(ios::fixed)<<setprecision(1)<<Sum*100<<endl;
        }
    }
    return 0;
}
