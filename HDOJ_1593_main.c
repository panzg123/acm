#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double PI=acos(-1);
    double R,V1,V2;
    while(scanf("%lf %lf %lf",&R,&V1,&V2))
    {
        if((R/V1)<(PI*R/V2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
