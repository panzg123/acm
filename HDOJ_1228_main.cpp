#include <iostream>
#include <cstring>
char map[][10] = {"zero", "one", "two", "three", "four",
"five", "six", "seven","eight", "nine"};

using namespace std;
int FindIndex(const char* a)
{
    for(int i=0;i<10;i++)
    {
        if(strcmp(a,map[i])==0)
            return i;
    }
    return 10;
}
int main()
{
    int n;
    char a[10],b[10];
    while(1)
    {
        int i=0,j=0;
        while(cin>>a&&strcmp(a,"+")!=0)
            i=i*10+FindIndex(a);
        while(cin>>b&&strcmp(b,"=")!=0)
            j=j*10+FindIndex(b);
        if(i==0&&j==0)
            return 0;
        cout<<i+j<<endl;
    }
    return 0;
}
