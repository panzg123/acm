#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int t,a[10010];
    int sum,x,i;
    cin>>t;
    while(t--)
    {
        sum=0;
        int n;
        cin>>n;
        for(i=0;i<n;i++)
           cin>>a[i];
        sort(a,a+n);
        x=n/2;
        for(i=0;i<n;i++)
           sum+=abs(a[x]-a[i]);
        cout<<sum<<endl;
    }
    return 0;
}
