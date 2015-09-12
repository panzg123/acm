#include<stdio.h>
#include<math.h>
int main()
{
    long t,x;
    float N;    //注意定义成float
    while(scanf("%f",&N)!=EOF)
    {
        t=(long)N,x=0;
        if(t<0)
            t=-t;
        while(t>1)
        {
            t/=2;
            x++;
        }
        printf("%ld %.6f\n",x,N/(2<<(x-1)));
    }
    return 0;
}
