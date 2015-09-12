#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Node
{
    int x,y,cost;
    int prex,prey;
};
int N,M;
char maze[105][105];
Node path[105][105];
int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};


int isOk(int x,int y)
{
    if(x>=0&&x<N&&y>=0&&y<M&&maze[x][y]!='X')
        return 1;
    else
        return 0;
}
void Init()
{
    int i,j;
    for(i=0; i<N; ++i)
        for(j=0; j<M; ++j)
            path[i][j].cost=-1;
}

void backPath(int x,int y)
{
    stack<Node> s;
    Node a,b;
    int cc=1,tmp;
    cout << "It takes " << path[N - 1][M - 1].cost
         << " seconds to reach the target position, let me show you the way." << endl;
    a=path[N-1][M-1];
    while(1)
    {
        if(a.x==0&&a.y==0)
            break;
        s.push(a);
        a=path[a.prex][a.prey];
    }

    a=path[0][0];
    while(!s.empty())
    {
        b=s.top();
        s.pop();
        if(maze[b.x][b.y]=='.')
            cout<<cc++<<"s:(" << a.x << "," << a.y << ")->(" << b.x << "," << b.y << ")" << endl;
        else
        {
            cout << cc++ << "s:(" << a.x << "," << a.y << ")->(" << b.x << "," << b.y << ")" << endl;
            tmp = maze[b.x][b.y] - '0';
            while(tmp--)
                cout << cc++ << "s:FIGHT AT (" << b.x << "," << b.y << ")" <<endl;
        }
        a = b;
    }
    cout<<"FINISH"<<endl;
}
int BFS(int x,int y)
{
    queue<Node> Q;
    Node a,b;
    a.x=a.y=a.cost = a.prex = a.prey = 0;
    if(maze[0][0] != '.')
        a.cost = maze[0][0] - '0';
    path[0][0] = a;
    Q.push(a);

    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(int i=0; i<4; ++i)
        {
            b.x = a.x + dir[i][0];
            b.y = a.y + dir[i][1];
            if(!isOk(b.x, b.y))
                continue;
            if(maze[b.x][b.y] == '.')
                b.cost = a.cost + 1;
            else
                b.cost = a.cost + maze[b.x][b.y]-'0' + 1;
            if(b.cost < path[b.x][b.y].cost || path[b.x][b.y].cost == -1)
            {
                b.prex = a.x;
                b.prey = a.y;
                path[b.x][b.y] = b;
                Q.push(b);
            }
        }
    }
    if(path[N - 1][M - 1].cost == -1)
    {
        cout << "God please help our poor hero." << endl;
        cout << "FINISH" << endl;
        return 0;
    }
    backPath(N-1, M-1);
}
int main()
{
    freopen("input.txt", "r", stdin);
	while(cin >> N >> M)
	{
		memset(maze, 0, sizeof(maze));
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				cin >> maze[i][j];
		Init();
		BFS(0, 0);
	}
    return 0;
}
