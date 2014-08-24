//11512698	2014-08-21 17:11:55	Accepted	2059	
//62MS	368K	969 B	G++	空信高手
//起点和终点，共n+2个点，n+2个状态，简单DP即可
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=150;
const double INF=0xfffff;
double DP[MAX];
int s[MAX];
using namespace std;
double min(double t1,double t2)
{
	return (t1<t2)?t1:t2;
}
int main()
{
	freopen("input.txt","r",stdin);
    int L;
	int N,C,T;
	int VR,VT1,VT2;
	double Time;
	while(cin>>L)
	{
		cin>>N>>C>>T>>VR>>VT1>>VT2;
		for(int i=1;i<=N;i++)
			cin>>s[i];
		s[N+1]=L;
		s[0]=0;
		DP[0]=0;
		for(int i=1;i<=N+1;i++)
		{
			DP[i] = INF;
			for(int j=0;j<i;j++)
			{
				int dis=s[i]-s[j];
				if(dis>C) Time=((double)C)/VT1+((double)(dis-C))/VT2;
				else Time=((double)dis)/VT1;
				Time+=DP[j];
				if(j>0)
					Time += T;
				DP[i]=min(DP[i],Time);
			}
		}
		if(DP[N+1]<((double)L/VR))
			cout<<"What a pity rabbit!"<<endl;
        else
			cout<<"Good job,rabbit!"<<endl;
	}
	return 0;
}
