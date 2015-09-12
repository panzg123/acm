/*
1272  小西的迷宫
并查集
判断两点：
1.任何2点的父节点不能相同->否则会导致2点间有多条通路
2.所有点只有1个集合
*/
#include <iostream>

using namespace std;

#define MAX 100001
int father[MAX];
int rank[MAX];

void Make_Set(int n)
{
    for(int i=0; i<=n; i++)
    {
        father[i]=i;
        rank[i]=0;
    }
}

int Find_Set(int x)
{
    if(x!=father[x])
        return Find_Set(father[x]);
    return x;
}

void Union(int x,int y)
{
    x=Find_Set(x);
    y=Find_Set(y);
    if(x==y)
        return;
    if(rank[x]>rank[y])
        father[y]=x;
    else if(rank[x]<rank[y])
        father[x]=y;
    else
    {
        rank[y]++;
        father[x]=y;
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    int a,b;
    while(scanf("%d %d", &a, &b))
    {
        if(a==0&&b==0)
        {
            cout<<"Yes\n";
            continue;
        }
        if(a==-1&&b==-1)
            break;
        Make_Set(MAX);
        rank[a]=1;
        rank[b]=1;
        Union(a,b);
        int flag=1;  // 表示是否有多条路
        while(scanf("%d %d", &a, &b) && (a+b))
        {
            rank[a]++;
            rank[b]++;
            if(Find_Set(a)==Find_Set(b))   //判断两点是否有多条路
                flag=0;
            Union(a,b);
        }
        int cnt=0;
        for(int i=1; i<=MAX; i++)
            if(rank[i]&&Find_Set(i)==i)
                cnt++;
        if(flag && cnt==1)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}
