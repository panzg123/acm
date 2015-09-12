#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a;
    while(scanf("%d",&a)&&a)
    {
        int y=(a-1960)/10;
        int bit=pow(2,1.0*(y+2));
        double cmp=0.0;
        int t=1;
        while(1)
        {
            cmp += (log10(t*1.0)/log10(2.0));
            if(cmp>bit)
                break;
            t += 1;
        }
        printf("%d\n",t-1);
    }
    return 0;
}
