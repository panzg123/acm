#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;
    int i;
    int a[1001];
    while(cin>>n>>m)
    {
        for(i=0;i<=n;i++)
            a[i]=i;
        for(i=1;i<m;i++)
            next_permutation(a+1,a+n+1);
        cout<<a[1];
        for(i=2;i<=n;i++)
            cout<<" "<<a[i];
        cout<<endl;
    }
    return 0;
}
