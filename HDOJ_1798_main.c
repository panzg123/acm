//求两圆相交的面积，分多种情况讨论
#include<stdio.h>
#include<math.h>
#define pi 2*asin(1.0)    //精确的给出pi的值很重要
int main ()
{
    double d,t1,t2,s1,t,x1,x2,y1,y2,m,n,r1,r2,a,b,s;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)
    {
        d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        if(r1<r2)
        {
            t=r1;
            r1=r2;
            r2=t;
        }
        if(d>(r1+r2)||(fabs(d-r1-r2)<1e-6))printf("0.000\n");
        else if((d+r2)<r1||(fabs(d+r2-r1)<1e-6)) printf("%.3lf\n",pi*r2*r2);
        else
        {
            m=(d*d+r2*r2-r1*r1)/(2*d*r2);
            n=(d*d+r1*r1-r2*r2)/(2*d*r1);
            a=acos(m);
            b=acos(n);
            s1=a*r2*r2+b*r1*r1;
            t2=r1*r1/2*sin(2*b);
            if(b<pi/2||(fabs(b-pi/2)<1e-6))
            {
                t1=r2*r2/2*sin(2*a);
                s=s1-t2-t1;
                printf("%.3lf\n",s);
            }
            else
            {
                t1=r2*r2/2*sin(2*(pi-a));
                s=s1-t2+t1;
                printf("%.3lf\n",s);
            }
        }
    }
    return 0;
}
