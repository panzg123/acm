#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
 //   freopen("input.txt","r",stdin);
    while(cin>>a>>b>>c&&(a!=0&&b!=0))
    {
        int res=1;
        while(c--)
            res*=10;
        if(a%res==b%res)
            cout<<"-1\n";
        else
            cout<<a+b<<endl;

    }
    return 0;
}
