/*
Anthor:panzg
Ë®Ìâ
*/
#include <iostream>

using namespace std;

bool is_prime(int n)
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    int m;
    while(cin>>m&&m)
    {
        for(int j=m/2; j<m; j++)
            if(is_prime(j)&&is_prime(m-j))
            {
                cout<<m-j<<" "<<j<<endl;
                break;
            }
    }
    return 0;
}
