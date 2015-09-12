#include <stdio.h>
#include <stdlib.h>
int compare(void *a,void *b)
{
    return (*(int*)a-*(int *)b);
}

int main()
{
    int T;
    int a[1000];
    scanf("%d",&T);
    while(T--)
    {
        int m=0;
        int i;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,m,4,compare);
        for(i=0;i<m-1;i++)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[i]);
    }
    return 0;
}
