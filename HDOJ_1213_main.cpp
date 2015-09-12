// Author: Tanky Woo
// HDOJ 1213
//并查集
// Accepted 1213 0MS 200K 1004 B C++ Tanky Woo
#include <iostream>
using namespace std;

#define MAX 100001

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
		rank[i] = 0;
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
		father[y] = x;
	else if(rank[x] < rank[y])
		father[x] = y;
	else
	{
		rank[y]++;
		father[x] = y;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int nCases;
	int a, b;
	scanf("%d", &nCases);
	while(nCases--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		Make_Set(N);
		for(int i=0; i<M; ++i)
		{
			scanf("%d %d", &a, &b);
			a = Find_Set(a);
			b = Find_Set(b);
			if(a != b)
			{
				Union(a, b);
				N--;
			}
		}
		printf("%d\n", N);
	}
	return 0;
}
