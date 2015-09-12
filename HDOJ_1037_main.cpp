#include <iostream>
using namespace std;
int main()
{
    int a1,a2,a3;
    while(cin>>a1>>a2>>a3)
    {
        bool flag = true;
        if(a1 <= 168 && flag)
        {
            flag = false;
            cout<<"CRASH "<<a1<<endl;
        }
        if(a2 <= 168 &&flag)
        {
            flag = false;
            cout<<"CRASH "<<a2<<endl;
        }
        if(a3 <= 168 && flag)
        {
            flag = false;
            cout<<"CRASH "<<a3<<endl;
        }
        if(flag)
            cout<<"NO CRASH"<<endl;
    }
    return 0;
}
