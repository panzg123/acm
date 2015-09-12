/*
Ä¸º¯Êý
Anthor:hdoj
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<iomanip>
#include<stack>
#include<map>
const int MAX=101;
int Min[MAX];
int Max[MAX];
int c1[MAX];
int c2[MAX];
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>Min[i]>>Max[i];
            sum+=Max[i];
        }
        for(int i=0; i<=m; i++)
        c1[i]=c2[i]=0;
        c1[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=sum; j++)
                for(int k=Min[i];j+k<=m&&k<=Max[i]; k++)
                    c2[j+k]+=c1[j];
                for(int i=0; i<=m; i++)
                c1[i]=c2[i],c2[i]=0;
        }
        cout<<c1[m]<<endl;
    }
    return 0;
}
