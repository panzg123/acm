//2013-10-31 16:08:12	Accepted	1175	3390MS	7464K	2757 B	C++	空信高手
#include <iostream>
#include <queue>
using namespace std;
const int INF=99;

int dir[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
int n,m,q;
int map[1005][1005];
int rec[1005][1005];
int sx,sy,ex,ey;
bool flag;
typedef struct
{
    int x,y;
    int turn;
    int d;
} node;
node start;
queue<node> que;
inline bool isIn(const node&p)
{
    if(p.x<1||p.y<1||p.x>n||p.y>m)
        return false;
    return true;
}
void BFS()
{
    node now,tmp;
    while(!que.empty())
    {
        now=que.front();
        que.pop();
        if(now.x==ex&&now.y==ey&&now.turn<=2)
        {
            flag=true;
            return;
        }
        for(int i=0; i<4; i++)
        {
            tmp.x=now.x+dir[i][0];
            tmp.y=now.y+dir[i][1];
            if(now.d==i)
            {
                tmp.turn=now.turn;
                tmp.d=i;
            }
            else
            {
                tmp.turn=now.turn+1;
                tmp.d=i;
            }
            if(isIn(tmp) && (map[tmp.x][tmp.y]==0||tmp.x==ex&&tmp.y==ey) && rec[tmp.x][tmp.y] >= tmp.turn)
            {
                rec[tmp.x][tmp.y]=tmp.turn;
                que.push(tmp);
            }
        }
    }
}
int main()
{
   // freopen("input.txt","r",stdin);
    while(scanf("%d %d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                scanf("%d",&map[i][j]);
        scanf("%d",&q);
        while(q--)
        {
            //cin >> sx >> sy >> ex >> ey;
            scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
            //memset(rec, INF, sizeof(rec));

            // 判断两点的值不相同，或其中一点值为0，或者两点是同一点，此时直接判为NO
            if((map[sx][sy] != map[ex][ey])
                    || (map[sx][sy] == 0)
                    || (map[ex][ey] == 0)
                    || (sx==ex && sy==ey))
            {
                cout << "NO\n";
                continue;
            }
            //------------
            // 清空队列que
            while(!que.empty())
                que.pop();
            // 初始条件，加入队列que
            for(int i=0; i<4; ++i)
            {
                start.x = sx;
                start.y = sy;
                start.turn = 0;
                start.d = i;
                que.push(start);
            }
            for(int i=1; i<=n; ++i)
                for(int j=1; j<=m; ++j)
                    rec[i][j] = 11;

            flag = false;
            rec[sx][sy] = 0;
            BFS();
            if(flag)
                cout << "YES\n";
            else
                cout << "NO\n";

        }
    }
    return 0;
}
