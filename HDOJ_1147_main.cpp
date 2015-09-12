//#include <iostream>
//#include <vector>
/////判断线段相交点数目
//using namespace std;
//vector<int> iVec;
//const  double  eps=1e-10;
//struct  point
//{
//    double  x, y;
//};
//double  min(double  a, double  b)
//{
//    return  a < b ? a : b;
//}
//double  max(double  a, double  b)
//{
//    return  a > b ? a : b;
//}
//bool inter(point a, point b, point c, point d)
//{
//    if ( min(a.x, b.x) > max(c.x, d.x) ||
//            min(a.y, b.y) > max(c.y, d.y) ||
//            min(c.x, d.x) > max(a.x, b.x) ||
//            min(c.y, d.y) > max(a.y, b.y) ) return  0;
//    double  h, i, j, k;
//    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
//    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
//    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
//    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
//    return  h * i <= eps && j * k <= eps;
//}
//point pnt[2][100009];
//int flag;
//int main()
//{
//    int num,count;
//    while(cin>>num&&num)
//    {
//        iVec.clear();
//        count=0;
//        for(int i=0; i<num; i++)
//            cin>>pnt[0][i].x>>pnt[0][i].y>>pnt[1][i].x>>pnt[1][i].y;
//        cout<<"Top sticks: ";
//        int i;
//        for(i=num-2; i>=0; i--)
//        {
//            flag=0;
//            for(int j=num-1;j>i;j--)
//            {
//                if(inter(pnt[0][i],pnt[1][i],pnt[0][j],pnt[1][j]))
//                   {
//                      flag=1; break;
//                   }
//            }
//            if(flag==0)
//                iVec.push_back(i+1);
//        }
//        int len = (int)iVec.size();
//        for (i = len-1; i >=0; --i)
//            cout<<iVec[i]<<", ";
//        cout<<num<<"."<<endl;
//    }
//    return 0;
//}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 100009;

struct Point
{
    double x, y;
};

struct Line
{
    Point p1, p2;
};

Line line[N];

vector<int> v;
double direction (Point p0, Point p1, Point p2)
{
    return ((p2.x - p0.x)*(p1.y - p0.y) - (p1.x - p0.x)*(p2.y - p0.y));
}
bool segments_intersect (Point p1, Point p2, Point p3, Point p4)
{
    double d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d3 = direction(p1, p2, p3);
    d4 = direction(p1, p2, p4);
    if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)))
        return true;
    else
        return false;
}

int main()
{
    int i, j, n;
    while (scanf("%d", &n)!=EOF && n)
    {
        v.clear();
        for (i = 1; i <= n; ++i)
            scanf("%lf %lf %lf %lf", &line[i].p1.x, &line[i].p1.y, &line[i].p2.x, &line[i].p2.y);
        v.push_back(n);
        for (j = n-1; j >= 1; j--)
        {
            for (i = n; i > j; --i)
            {
                if (segments_intersect(line[j].p1, line[j].p2, line[i].p1, line[i].p2))
                    break;
            }
            if (i <= j)
                v.push_back(j);
        }
        int len = (int)v.size();
        printf("Top sticks: ");
        for (i = len -1; i > 0; --i)
            printf("%d, ", v[i]);
        printf("%d.\n", v[0]);
    }
    return 0;
}
