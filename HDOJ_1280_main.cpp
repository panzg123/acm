#include <iostream>
#include <queue>

using namespace std;
int arr[3005];
int main()
{
    int n,m,i,j;
    while(cin>>n>>m)
    {
        priority_queue<int> qInt;
        for(i=0;i<n;i++)
            cin>>arr[i];
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
            {
                qInt.push(arr[i]+arr[j]);
            }
        for(i=0;i<m-1;i++)
            {
                cout<<qInt.top()<<" ";
                qInt.pop();
            }
        cout<<qInt.top()<<endl;
    }
    return 0;
}
