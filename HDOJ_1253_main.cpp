/*   //Code1，有问题，超内存，找不到问题
#include <iostream>
#include <queue>
using namespace std;

int Castle[51][51][51];  // the castle
//int vis[51][51][51];  // have visited
int dir[6][3]=        // direction
{
    {0, 0, 1},   // up
    {0, 0, -1},  // down
    {1, 0, 0},   // left
    {-1, 0, 0},  // right
    {0, 1, 0},   // front
    {0, -1, 0},  // after
};

int A, B, C, T, nCases;

typedef struct node
{
    int x, y, z;
    int step;
} Node;

void BFS()
{
    //  memset(vis, 0, sizeof(vis));
    Castle[0][0][0] = 1;
    queue<Node> Que;
    Node pre, last;
    pre.x = pre.y = pre.z = pre.step = 0;
    Que.push(pre);
    while(!Que.empty())
    {
        pre = Que.front();
        Que.pop();
        if(pre.step > T)   // 剪枝一
            break;
        if(abs(A-1-pre.x) + abs(B-1-pre.y) + abs(C-1-pre.z) > T)  //剪枝二,这个剪枝使时间减少了500ms。
            break;
        if(pre.x==A-1 && pre.y==B-1 && pre.z==C-1)
        {
            printf("%d\n", pre.step);
            return;
        }
        for(int i=0; i<6; i++)
        {
            last.x = pre.x+dir[i][0];
            last.y = pre.y+dir[i][1];
            last.z = pre.z+dir[i][2];
            last.step = pre.step+1;
            if(last.x>=0 && last.x<A && last.y>=0 && last.y<B&&last.z>=0&&last.z<C&&Castle[last.x][last.y][last.z]==0)
            {
                Que.push(last);
                Castle[pre.x][pre.y][pre.z]=1;
            }
        }
    }
}
int main()
{
    int i,j,k;
  //  freopen("input.txt","r",stdin);
    scanf("%d",&nCases);
    while(nCases--)
    {
        int to=0;
        scanf("%d%d%d%d",&A,&B,&C,&T);
        for(i=0; i<A; i++)
            for(j=0; j<B; j++)
                for(k=0; k<C; k++)
                {
                    scanf("%d",&Castle[i][j][k]);
                    if(Castle[i][j][k]==0)to++;
                }
        if(A+B+C-3>T||to<A+B+C-3||Castle[A-1][B-1][C-1]==1)//剪枝
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
            BFS();
    }
    return 0;
}
*/
//Code2，2013-12-03 18:46:17	Accepted	1253	828MS	2280K	1534 B	C++	空信高手
#include<string.h>
#include<stdio.h>

int a,b,c,pos[52][52][52];

struct POS
{
    int x,y,z;
} q[125110];

int bfs()
{
    int s,e,i;
    struct POS temp,t;
    int jx[] = {0,0,0,0,1,-1};
    int jy[] = {0,0,-1,1,0,0};
    int jz[] = {-1,1,0,0,0,0};
    s = e = 0;
    q[e].x = q[e].y = q[e].z = 0;
    e++;
    while(s < e)
    {
        temp = q[s];
        s++;
        if(temp.x == a-1 && temp.y == b-1 && temp.z == c-1) return (1);
        for(i = 0; i < 6; i++)
        {
            t.x = temp.x + jx[i];
            t.y = temp.y + jy[i];
            t.z = temp.z + jz[i];
            if(t.x >= 0 && t.x < a && t.y >= 0 && t.y < b && t.z >= 0 && t.z < c && pos[t.x][t.y][t.z] == 0 )
            {
                q[e] = t;
                e++;
                pos[t.x][t.y][t.z] = pos[temp.x][temp.y][temp.z] + 1;
            }
        }
    }
    return 0;
}

int main()
{
    memset(pos,-1,sizeof(pos));
    int i,j,k,js,t;
    scanf("%d",&js);
    while(js--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&t);
        for(i = 0; i < a; i++)
            for(j = 0; j < b; j++)
                for(k = 0; k < c; k++)
                {
                    scanf("%d",&pos[i][j][k]);
                    if(pos[i][j][k] == 1) pos[i][j][k] = -1;
                }
        pos[0][0][0] = 0;//起点是 1 也能走
        if(!bfs()) printf("-1\n");
        else if(pos[a-1][b-1][c-1] <= t) printf("%d\n",pos[a-1][b-1][c-1]);
        else printf("-1\n");
    }
    return 0;
}
