#include <iostream>
#include <cstdio>
using namespace std;

bool Is_leap(int year)
{
    if(((year%4==0)&&(year%100!=0))||(year%400==0)) return 1;
    else return 0;
}
int main()
{
    int year,month,day;
    int n;
    while(cin>>n&&n!=0)
    {
        while(n--)
        {
            scanf("%d-%d-%d",&year,&month,&day);
            if(month==2&&day==29)
            {
                cout<<-1<<endl;
                continue;
            }
            int run=0;
            if(month>=3)
            {
                for(int i=1; i<=18; ++i)
                    if(Is_leap(year+i))
                        run++;
            }
            else
            {
                for(int i=0; i<18; ++i)
                    if(Is_leap(year+i))
                        run++;
            }
            cout << 365*18+run << endl;

        }
    }
    return 0;
}
