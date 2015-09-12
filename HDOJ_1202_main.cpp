#include <iostream>
#include <iomanip>
using namespace std;
#define N 100
int Point(double grade)
{
    if(grade>=90) return 4;
    else if(grade>=80) return 3;
    else if(grade>=70) return 2;
    else if(grade>=60) return 1;
    else if(grade>=0)  return 0;
}

int main()
{
    //  freopen("input.txt","r",stdin);
    int n=0;
    while(cin>>n&&n!=0)
    {
        double s,p,sumS=0,sumP=0;
        while(n--)
        {
            cin>>s>>p;
            if(p!=-1)
            {
                sumP+=Point(p)*s;
                sumS+=s;
            }
        }
        if(sumS==0) cout<<"-1"<<endl;
        else  cout<<setiosflags(ios::fixed)<<setprecision(2)<<sumP/sumS<<endl;

    }
    return 0;
}
