//经典深度优先搜索问题
#include <iostream>
#include <vector>
using namespace std;
int n;
int result[20];
vector< vector<int> > res; //保存序列
bool prime[]={0,0 ,1 ,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1};
bool IsPrime(int num)
{
    return prime[num];
}
bool IsIn(int list[],int len,int value)  //判断是否已经加入序列
{
    for(int i=0;i<len;i++)
    {
        if(list[i]==value)
            return true;
    }
    return false;
}
void FindCircle(int i)
{
    int count=0;
    for(int j=2;j<=n;j++)
    {
        if(!IsIn(result,i,j)&&IsPrime(result[i-1]+j))
        {
            result[i]=j;
            count++;
            FindCircle(i+1);
        }
    }
     if(count==0)
            return;
     if((i==(n-1))&&IsPrime(result[n-1]+1))
     {
         vector<int> ivec;
         for(int k=0;k<n;k++)
            ivec.push_back(result[k]);
         res.push_back(ivec);
     }
}
int main()
{
    int Case=0;
    while(cin>>n)
    {
        Case++;
        res.clear();
        result[0]=1;
        cout<<"Case "<<Case<<":"<<endl;
        FindCircle(1);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size()-1;j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<res[i][res[i].size()-1]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
