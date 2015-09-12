#include <stdio.h>

int main(int argc, char* argv[])
{
    __int64 n,b,i,j;
    int a[20];
    while(scanf("%I64dd",&n)!=EOF&&n!=0)
    {
        for(j=0; j<20; j++)
            a[j]=0;

        for (i=2; i<=n;)
        {

            if (n%i==0)
            {
                a[i]++;

                n=n/i;
            }
            else i++;
        }
        b=a[i]+1;
        while(i>=2)
        {
            b=b*(a[i-1]+1);
            i--;
        }
        printf("%I64d\n",b);
    }
    return 0;
}
