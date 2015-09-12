//¶þ·ÖËÑË÷
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double pie[10005];
int T,N,F;
double PI=acos(-1.0);
bool test(double x)
{
    int count=0;
    for(int i=1; i<=N; i++)
    {
        count+=int(pie[i]/x);
    }
    if(count>=F+1)
        return 1;
    else
        return 0;
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>F;
        double Sum=0.0;
        int rad;
        for(int i=1; i<=N; i++)
        {
            cin>>rad;
            pie[i]=(rad*rad*PI);
            Sum+=pie[i];
        }
        double l=0.0;
        double r=Sum/(F+1);
        double mid;
        while((r-l) > 1e-6)
        {
            mid=(l+r)/2.0;
            if(test(mid))
                l=mid;
            else
                r=mid;
        }
        cout<<fixed<<setprecision(4)<<mid<<endl;
    }
    return 0;
}
