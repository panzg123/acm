#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,a;
    while(cin>>n)
    {
        int i,count=0;
        map<int,int> m;
        map<int,int>::iterator iter;
        for(i=0; i<n; i++)
        {
            scanf("%d",&a);
            m[a]++;
        }
        for(iter=m.begin();iter!=m.end();iter++)
        {
            if(iter->second>count)
                count=iter->second;
        }
        printf("%d\n",count);
    }
    return 0;
}
