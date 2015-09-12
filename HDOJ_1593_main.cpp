#include <stdio.h>
#include <stdlib.h>
#include <cmath>
int main()
{
    double PI=acos(-1.0);
    double R,V1,V2;
    while(scanf("%lf %lf %lf",&R,&V1,&V2)!=EOF)
    {
        double r=(R/V2)*V1;
        double result1=(R-r)/V1;
        double result2=PI*R/V2;
        if(result1<result2)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
