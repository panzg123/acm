// 与或处理
#include <iostream>
#include <cstring>
using namespace std;
char a[8];
int FindIndex(const char *b)
{
    int i;
    for(i=0;i<strlen(b);i++)
    {
        if(b[i]=='1')
        break;
    }
    return i;
}
int Count(int m)
{
    int result=1;
    while(m--)
    {
        result*=2;
    }
    return result;
}
int main()
{
    int n,i;
    while(cin>>n&&n!=0)
    {
        i=0;
        while(n)
        {
            a[i++]=n%2+'0';
            n/=2;
        }
        a[i]='\0';
        cout<<Count(FindIndex(a))<<endl;
    }
    return  0;
}
