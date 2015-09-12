#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    // freopen("input.txt","r",stdin);
    int n,a;

    while(scanf("%d",&n)&&n)
    {
        map<int,int> m;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a);
            m[a]++;
        }
        scanf("%d",&a);
        printf("%d\n",m[a]);
    }
    return 0;
}

