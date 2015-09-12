//没有用公式
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int FactorialDigits(int n)
{
    int i=0;
    double Sum=0.0;
    for(i=1;i<=n;i++)
    {
        Sum+=log10(i);
    }
    return floor(Sum)+1;
}
int main()
{
    int n,m,count;
    while(scanf("%d",&n)!=EOF)
    {
        count=n;
        while(count--)
        {
            scanf("%d",&m);
            printf("%d\n",FactorialDigits(m));
        }
    }
    return 0;
}

/*  可以用公式的
#include <iostream>
#include<math.h>
using namespace std;

#define M_PI 3.141592657
#define M_E 2.71828182845904523536028747135266250

int main(void)
{
    int num;
    cin>>num;
    int n;
    double sum;
    for(int i=0; i<num; i++)
    {
        cin>>n;
        sum=log10(sqrt(2*M_PI*n))+n*log10(n/M_E);
        cout<<(int)sum+1<<endl;
    }
    return 0;
}
*/
