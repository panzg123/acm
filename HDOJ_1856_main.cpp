//并查集
#include <iostream>
using namespace std;

#define MAX 10000001

// father[x]表示x的父节点
int father[MAX];
// rank[x]表示x的秩
int rank[MAX];

// 初始化
void Make_Set(int n)
{
    for(int i=1; i<=n; ++i)
    {
        father[i] = i;
        rank[i] = 1;
    }
}

// 查找
int Find_Set(int x)
{
    if(x != father[x])
        return Find_Set(father[x]);
    return x;
}

// 合并
void Union(int x, int y)
{
    x = Find_Set(x);
    y = Find_Set(y);
    if(x == y)  // x,y在同一个集合
        return;
    if(rank[x] > rank[y])
    {
        father[y] = x;
        rank[x] += rank[y];
    }
    else if(rank[x] < rank[y])
    {
        father[x] = y;
        rank[y] += rank[x];
    }
    else
    {
        father[x] = y;
        //rank[y]++;
        rank[y] += rank[x];
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    int nNum;
    while(scanf("%d", &nNum) != EOF)
    {
        Make_Set(MAX);
        if(nNum==0)
        {
            printf("1\n");
            continue;
        }
        for(int i=0; i<nNum; ++i)
        {
            scanf("%d %d", &a, &b);
            Union(a, b);
            //printf("rank[%d]=%d rank[%d]=%d\n", a, rank[a], b, rank[b]);
        }
        int _max=0;
        for(int i=0; i<=MAX; ++i)
            //printf("%d ", rank[i]);
            if(_max < rank[i])
                _max = rank[i];
        printf("%d\n", _max);
    }
    return 0;
}
