#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int x;
    int y;
} point[1001];
int main()
{
    int n,i,p,q;
    while(scanf("%d",&n)&&n)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        for(i=0; i<n; i++)
        {
            p=(point[(i+1)%n].x-point[i].x)*(point[(i+2)%n].y-point[(i+1)%n].y);
            q=(point[(i+2)%n].x-point[(i+1)%n].x)*(point[(i+1)%n].y-point[i].y);
            if(p<q) break;;
        }
        if(i==n)printf("convex\n");
        else printf("concave\n");
    }
    return 0;
}
