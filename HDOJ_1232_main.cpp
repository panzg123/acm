/*
anthor:wutianqi
����Ĳ��鼯Ӧ��
*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

#define MAX 1005
/* father[x]��ʾx�ĸ��ڵ� */
int father[MAX];
/* rank[x]��ʾx���� */
int rank[MAX];

/* ��ʼ������ */
void Make_Set(int x)
{
        father[x] = x;
        rank[x] = 0;
}

/* ����xԪ�����ڵļ���,����ʱѹ��·�� */
int Find_Set(int x)
{

        if(x != father[x])
        {
                father[x] = Find_Set(father[x]);
        }
        return father[x];
}

/* ���Ⱥϲ�x,y���ڵļ��� */
void Union(int x, int y)
{
        x = Find_Set(x);
        y = Find_Set(y);
        if (x == y) return;
        if (rank[x] > rank[y])
        {
                father[y] = x;
        }
        else
        {
                if (rank[x] == rank[y])
                {
                        rank[y]++;
                }
                father[x] = y;
        }
}
int N, M;
int main()
{
    int a, b;
    while(scanf("%d", &N) && N)
    {
        for(int i=1; i<=N; ++i)
            Make_Set(i);
        scanf("%d", &M);
        while(M--)
        {
            scanf("%d %d", &a, &b);
            Union(a, b);
        }
        int cnt = -1;
        for(int i=1; i<=N; ++i)
            if(father[i]==i)
                cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
