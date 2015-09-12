#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,Sum,a,m;
    while(scanf("%d",&m)!=EOF)
    {
        while(m--)
        {
            scanf("%d",&n);
            Sum=0;
            while(n--)
            {
                scanf("%d",&a);
                Sum+=a;
            }
            printf("%d\n",Sum);
        }
    }
    return 0;
}
