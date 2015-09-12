/*
author:panzg
time:2013/10/22
graham求凸包
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
};
point p[50010],s[50010];
bool mult(point sp,point ep,point op)
{
    return (sp.x-op.x)*(ep.y-op.y)>=(ep.x-op.x)*(sp.y-op.y);
}
bool  operator  < (const point &l,  const point &r)
{
    return  l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[],int n,point res[])
{
    int i,len,top=1;
    sort(pnt,pnt+n);
    if(n==0) return 0;
    res[0]=pnt[0];
    if(n==1) return 1;
    res[1]=pnt[1];
    if(n==2) return 2;
    res[2]=pnt[2];
    for(i=2; i<n; i++)
    {
        while(top&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    len=top;
    res[++top]=pnt[n-2];
    for(i=n-3; i>=0; i--)
    {
        while(top!=len&&mult(pnt[i],res[top],res[top-1])) top--;
        res[++top]=pnt[i];
    }
    return top;
}
double area(point i,point j,point k)
{
    double s=fabs(double(i.x*j.y+j.x*k.y+k.x*i.y-
                         i.y*j.x-j.y*k.x-k.y*i.x)/2);
    return s;
}
double maxx(double x,double y)
{
    return x>y?x:y;
}
int main()
{
    int n,m,i,j,k;
    double ans,t,t1;
    freopen("input.txt","r",stdin);
    while(cin>>n&&n!=0)
    {
        m=0;
        memset(p,0,sizeof(p));
        memset(s,0,sizeof(s));
        for(i=0; i<n; i++)
            cin>>p[i].x>>p[i].y;
        m=graham(p,n,s); //求凸包

        //暴力枚举所有的三角形
        for(ans=0,i=1; i<=m; i++)
            for(j=i+1; j<=m; j++)
                for(k=j+1; k<=m; k++)
                    ans=maxx(ans,area(s[i],s[j],s[k]));
        printf("%.2f\n",ans);
    }
    return 0;
}
