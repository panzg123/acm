/*
*DpË®Ìâ
*Anthor£ºpanzg
*/
#include <iostream>

using namespace std;

int n,t;
int a[110][110];
int main()
{

   // freopen("input.txt","r",stdin);
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            memset(a,0,sizeof(a));
            for(int i=0; i<n; i++)
                for(int j=0; j<=i; j++)
                    cin>>a[i][j];
            for(int k=n-2; k>=0; k--)
                for(int m=0; m<=k; m++)
                    a[k][m]+=(a[k+1][m]>a[k+1][m+1])?a[k+1][m]:a[k+1][m+1];
            cout<<a[0][0]<<endl;
        }

    }
    return 0;
}
