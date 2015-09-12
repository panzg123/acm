/*
//hdoj 2037
//结构体排序
//Anthor:panzg
*/

#include <iostream>

using namespace std;

typedef struct
{
    int first;
    int end;
} Time;
Time t[101];

int compare (const void * a, const void * b)
{
//    Time *c=(Time*)a;
//    Time *d=(Time*)d;
//    return (*c).end-(*d).end;     //报错
//    return (*(Time *)a).end > (*(Time *)b).end;       //报错
    return (*(Time *)a).end > (*(Time *)b).end ? 1 : -1;        //正确
}

int main()
{
    int n,count,pre;
    //freopen("input.txt","r",stdin);
    while(cin>>n&&n!=0)
    {
        for(int i=0; i<n; i++)
            cin>>t[i].first>>t[i].end;
        qsort(t,n,sizeof(Time),compare);
        if(n>=1) count=1;
        else count=0;
        pre=t[0].end;
        for(int i=1; i<n; i++)
            if(t[i].first>=pre)
            {
                count++;
                pre=t[i].end;
            }
        cout<<count<<endl;
    }
    return 0;
}
