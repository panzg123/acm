#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,m,i;
    while(cin>>n)
    {
        int Count=0,Current;
        map<int,int> M;
        map<int,int>::iterator iter;
        for(i=0; i<n; i++)
        {
            cin>>m;
            M[m]++;
        }
        for(iter=M.begin(); iter!=M.end(); iter++)
        {
            if(iter->second>Count)
            {
                Count=iter->second;
                Current=iter->first;
            }
        }
        cout<<Current<<endl;
    }
    return 0;
}
