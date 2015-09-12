//2013-12-03 10:44:00	Accepted	2717	15MS	840K	1143 B	C++	ø’–≈∏ﬂ ÷
#include <iostream>
#include <queue>
using namespace std;



#define MAX 100001
int d[MAX];
int N,K;
void BFS()
{
    memset(d,0,sizeof(d));
    queue<int> q;
    q.push(N);

    while(!q.empty())
    {
        int u=q.front();
        if(u==K) return;
        q.pop();

        int next=u-1;
        if(next>=0&&next<MAX&&!d[next])
        {
            q.push(next);
            d[next]=d[u]+1;
        }
        next=u+1;
        if(next>=0&&next<MAX&&!d[next])
        {
            q.push(next);
            d[next]=d[u]+1;
        }
        next=2*u;
        if(next>=0&&next<MAX&&!d[next])
        {
            q.push(next);
            d[next]=d[u]+1;
        }
    }
}
int main()
{
  //  freopen("input.txt", "r", stdin);
    while(scanf("%d%d",&N,&K)!=EOF)
    {
        if(N==K)
            printf("0\n");
        else
        {
            BFS();
            printf("%d\n",d[K]);
        }
    }
    return 0;
}
