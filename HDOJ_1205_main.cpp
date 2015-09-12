#include <iostream>
#include <vector>
using namespace std;

int main()
{
   // freopen("input.txt","r",stdin);
    __int64 T,N,a,Sum,Max;
    while(cin>>T&&T)
    {
        while(T--)
        {
            Sum=Max=0;
            cin>>N;
            vector<__int64> m;
            for(__int64 i=0; i<N; i++)
            {
                cin>>a;
                if(a>Max)
                    Max=a;
                m.push_back(a);
                Sum+=a;
            }

       //     result = max_element(m.begin(),m.end());
            if(Max>(Sum-Max+1))
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }

    }
    return 0;
}
