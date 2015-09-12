// Author: Tanky Woo
// HDOJ 1213
//���鼯
// Accepted 1213 0MS 200K 1004 B C++ Tanky Woo
#include <iostream>
using namespace std;

#define MAX 100001

// father[x]��ʾx�ĸ��ڵ�
int father[MAX];
// rank[x]��ʾx����
int rank[MAX];

// ��ʼ��
void Make_Set(int n)
{
	for(int i=1; i<=n; ++i)
	{
		father[i] = i;
		rank[i] = 0;
	}
}

// ����
int Find_Set(int x)
{
	if(x != father[x])
		return Find_Set(father[x]);
	return x;
}

// �ϲ�
void Union(int x, int y)
{
	x = Find_Set(x);
	y = Find_Set(y);
	if(x == y)  // x,y��ͬһ������
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
