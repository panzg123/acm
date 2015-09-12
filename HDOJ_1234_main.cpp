#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,m;
    string id,openid,closeid, tr,tl,timemin,timemax;
    while(cin>>n&&n)
    {
        while(n--)
        {
            cin>>m;
            timemin="9";
            timemax="0";

            while(m--)
            {
                cin>>id>>tr>>tl;

                if(timemin>=tr)timemin=tr,openid=id;
                if(timemax<=tl)timemax=tl,closeid=id;
            }
            cout<<openid<<" "<<closeid<<endl;
        }
    }
    return 0;
}
