#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    double D,V;
    while(scanf("%lf %lf",&V,&D)!=EOF)
    {
        int i,j,Sum=0,flag=0;
        for(i=1;;i++)
        {
            for(j=1; j<=i; j++)
            {
                V-=D;
                Sum++;
                if(V<=0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag) break;
            Sum++;
        }
        printf("%d\n",Sum);
    }
    return 0;
}
