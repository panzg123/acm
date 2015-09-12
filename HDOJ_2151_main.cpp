//2013-12-03 16:11:56	Accepted	2151	0MS	356K	566 B	C++	���Ÿ���
//DP����
// dp[M][T];
// ��ʾ��Mʱ���ϣ��ߵ�T�ķ�����
// dp[M][T] = dp[M-1][T-1] + dp[M-1][T+1]
// ��ʼ��dp[0][P] = 1;
#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int N,P,M,T;
int cmt[MAX][MAX];
int main()
{
  //  freopen("input.txt","r",stdin);
    while(cin>>N>>P>>M>>T)
    {
        memset(cmt,0,sizeof(cmt));
        cmt[0][P]=1;
        for(int i=1; i<=M; i++)
            for(int j=1; j<=N; j++)
            {
                if(j>=2)
                    cmt[i][j]+=cmt[i-1][j-1];
                if(j<=N-1)
                    cmt[i][j]+=cmt[i-1][j+1];
            }
        cout<<cmt[M][T]<<endl;
    }
    return 0;
}
