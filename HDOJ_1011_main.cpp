#include <iostream>

using namespace std;

const int nMax=105;
int map[nMax][nMax];
int d[nMax][nMax];
int visit[nMax];

struct Room
{
    int bugs,brains;
}room[nMax];
int N,M;

//动态规划，等于分层处理，每次处理一层。递归遍历树形结构
void dp(int u)
{
    visit[u]=1;
    int r=(room[u].bugs+19)/20;
    for(int i=M;i>=r;i--)
        d[u][i]=room[u].brains;
    for(int v=1;v<=N;++v)
    {
        if(map[u][v]&&!visit[v])
        {
            dp(v);
            for(int j=M;j>=r;j--)
            {
                for(int k=1;k<=j-r;k++)
                    d[u][j]=max(d[u][j],d[u][j-k]+d[v][k]);
            }
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    while(scanf("%d %d",&N,&M)!=EOF)
    {
        if(N==-1) break;
        for(int i=1;i<=N;i++)
            scanf("%d %d",&room[i].bugs,&room[i].brains);
        memset(map,0,sizeof(map));
        for(int i=1;i<N;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            map[a][b]=map[b][a]=1;
        }
        if(!M)
        {
            printf("0\n");
            continue;
        }
        memset(d,0,sizeof(d));
        memset(visit,0,sizeof(visit));
        dp(1);
        printf("%d\n",d[1][M]);
    }
    return 0;
}
