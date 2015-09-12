/*
//anthor:cug panzg
//标准筛选法。因子和
*/
#include <iostream>

using namespace std;

int sum[1000001],flag[1001];
int main()
{
  //  freopen("input.txt","r",stdin);
    for(int i=1; i<500000; i++)
        for(int j=2*i; j<1000001; j+=i)
            sum[j]+=i;
    for(int i=1; i<1000001; i++)
        if(sum[i]<1000)
            flag[sum[i]]=1;
    int n,a;
    while(cin>>n&&n)
    {
        while(n--)
        {
            cin>>a;
            if(flag[a])
                cout<<"no\n";
            else
                cout<<"yes\n";
        }
    }
    return 0;
}
