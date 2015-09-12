//多边形重心
#include<iostream>
#include<iomanip>
using namespace std;
#define MAX 1000010
typedef struct
{
	double x;
	double y;
}Point;
Point p[MAX];

Point Gravity(int n)//求重心
{
	double area = 0;
	Point center;
	center.x = 0;
	center.y = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i++)
	{
		area += (p[i].x * p[i + 1].y - p[i].y * p[i + 1].x) / 2; //叉乘一半是三角形面积
		center.x += (p[i].x * p[i + 1].y - p[i].y * p[i + 1].x) * (p[i].x + p[i + 1].x);
		center.y += (p[i].x * p[i + 1].y - p[i].y * p[i + 1].x) * (p[i].y + p[i + 1].y);
	}
	center.x /= 6 * area;
	center.y /= 6 * area;

	return center;
}

int main()
{
	int n, i, cas;
	cin >> cas;
	while(cas--){
		cin >> n;
		for(i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		Point gra = Gravity(n);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << gra.x << ' ' << gra.y << endl;
	}
	return 0;
}
/*   模版，超时
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    double x,y;
}Point;
Point bcenter(Point pnt[],int n)
{
    int i=0;
    Point p,s;
    double tp,area=0,tpx=0,tpy=0;
    p.x=pnt[0].x; p.y=pnt[0].y;
    for(i=1;i<=n;++i)
    {
        s.x=pnt[(i==n)?0:i].x;
        s.y=pnt[(i==n)?0:i].y;
        tp=(p.x*s.y-s.x*p.y);
        area+=tp/2;
        tpx+=(p.x+s.x)*tp;
        tpy+=(p.y+s.y)*tp;
        p.x=s.x; p.y=s.y;
    }
    s.x=tpx/(6*area); s.y=tpy/(6*area);
    return s;
}
int main()
{
    int num;
    Point a[1000];
    while(scanf("%d",&num))
    {
        int count=num;
        while(count--)
        {
            int i=0,N;
            scanf("%d",&N);
            for(i=0;i<N;i++)
            {
                scanf("%lf %lf",&a[i].x,&a[i].y);
            }
            Point result=bcenter(a,N);
            printf("%.2lf %.2lf\n",result.x,result.y);
        }
    }
    return 0;
}
*/
