#include <iostream>
#include <algorithm>
using namespace std;

typedef struct time
{
    int h, m, s;
    int tot;
} time;

typedef struct stu
{
    int p;
    time t;
    int id;
    int sco;
} stu;

stu ss[105], ss2[105];
int n;

bool cmp (stu e1, stu e2 )
{
    if(e1.p != e2.p)
        return e1.p > e2.p;
    else
        return e1.t.tot < e2.t.tot;
}

bool cmp2(stu e1, stu e2)
{
    return e1.id < e2.id;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //bool flag = 0;

    while(cin >> n && n != -1)
    {
        //if(flag == 1)
        //    cout << endl;
        //flag = 1;
        int c[6];  // 1, 2, 2, 4;
        memset(c, 0, sizeof(c));
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        int cnt = 0;
        for(int i=0; i<n; ++i)
        {
            ss[i].id = i+1;
            scanf("%d", &ss[i].p);
            scanf("%d:%d:%d", &ss[i].t.h, &ss[i].t.m, &ss[i].t.s);
            ss[i].t.tot = ss[i].t.h*3600 + ss[i].t.m*60 + ss[i].t.s;
        }
        sort(ss, ss+n, cmp);
        for(int i=0; i<n; ++i)
        {
            //cout << ss[i].p << "    " << ss[i].t.h << " " << ss[i].t.m << " " << ss[i].t.s << endl;
            c[ss[i].p]++;
        }
        for(int i=0; i<n; ++i)
        {
            if(ss[i].p == 5)
                ss[i].sco = 100;
            else if(ss[i].p == 4)
            {
                ++c4;
                if(c4 <= c[4]/2)
                    ss[i].sco = 95;
                else
                    ss[i].sco = 90;
            }
            else if(ss[i].p == 3)
            {
                ++c3;
                if(c3 <= c[3]/2)
                    ss[i].sco = 85;
                else
                    ss[i].sco = 80;
            }
            else if(ss[i].p == 2)
            {
                ++c2;
                if(c2 <= c[2]/2)
                    ss[i].sco = 75;
                else
                    ss[i].sco = 70;
            }
            else if(ss[i].p == 1)
            {
                ++c1;
                if(c1 <= c[1]/2)
                    ss[i].sco = 65;
                else
                    ss[i].sco = 60;
            }
            else
                ss[i].sco = 50;
        }
        sort(ss, ss+n, cmp2);
        for(int i=0; i<n; ++i)
        {
            //cout << ss[i].p << "    " << ss[i].t.h << " " << ss[i].t.m << " " << ss[i].t.s << endl;
            //c[ss[i].p]++;
        }
        for(int i=0; i<n; ++i)
            cout << ss[i].sco << endl;
        cout << endl;
    }
}
