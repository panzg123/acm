// Author: Tanky Woo
// Blog: www.WuTianQi.com
// Title: HDOJ 1033 Edge
// About: Ä£Äâ

#include <iostream>
#include <string>
using namespace std;

typedef struct Point{
    int x, y;
}Point;

Point p;
string s;
int dir; // 1-up, 2-down, 3-left, 4-right

void funA()
{
    if(dir == 1)
    {
        p.x += 10;
        dir = 4;
    }
    else if(dir == 2)
    {
        p.x -= 10;
        dir = 3;
    }
    else if(dir == 3)
    {
        p.y += 10;
        dir = 1;
    }
    else
    {
        p.y -= 10;
        dir = 2;
    }
    cout << p.x << " " << p.y << " lineto" << endl;
}

void funV()
{
    if(dir == 1)
    {
        p.x -= 10;
        dir = 3;
    }
    else if(dir == 2)
    {
        p.x += 10;
        dir = 4;
    }
    else if(dir == 3)
    {
        p.y -= 10;
        dir = 2;
    }
    else
    {
        p.y += 10;
        dir = 1;
    }
    cout << p.x << " " << p.y << " lineto" << endl;
}

int main()
{
    while(cin >> s)
    {
        cout << "300 420 moveto" << endl;
        cout << "310 420 lineto" << endl;
        dir = 4;
        p.x = 310;
        p.y = 420;
        for(int i=0; i<s.size(); ++i)
        {
            if(s[i] == 'A')
                funA();
            else
                funV();
        }
        cout << "stroke\nshowpage\n";
    }
    return 0;
}
