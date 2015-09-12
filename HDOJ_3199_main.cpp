#include <iostream>

using namespace std;


__int64 humble[100000];
__int64  _min(__int64 a,__int64 b,__int64 c)
{
    __int64 m;
    if(a>b)
        m=b;
    else
        m=a;

    if(m>c)
        m=c;
    return m;
}

int main()
{
    int p1,p2,p3,n;
    __int64 a1,a2,a3;
    int index1,index2,index3;
    while(scanf("%d %d %d %d", &p1, &p2, &p3, &n) != EOF)
    {
        index1=index2=index3=0;
        humble[0]=1;
        for(int i=1; i<=n; i++)
        {
            a1 = p1*humble[index1];
            a2 = p2*humble[index2];
            a3 = p3*humble[index3];
            humble[i] =  _min(a1, a2, a3);
            if(humble[i] == a1)
                index1++;
            if(humble[i] == a2)
                index2++;
            if(humble[i] == a3)
                index3++;
        }
        printf("%I64d\n", humble[n]);
    }
    return 0;
}
