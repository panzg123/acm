#include <iostream>
#include <cstring>
using namespace std;
char a[12],b[7];
int main()
{
    int n=0;
 //   freopen("input.txt","r",stdin);
    while(cin>>n)
    {
        while(n--)
        {
            memset(b,'6',sizeof(b));
            cin>>a;
            memcpy(b+1,a+6,sizeof(char)*5);
            b[6]='\0';
            cout<<b<<endl;
        }
    }
    return 0;
}
