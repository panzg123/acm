#include <iostream>

using namespace std;
const long int nMax=500100;
const int N = 1001;

int p[nMax],r[nMax];
int  a[N], f[N], d[N]; // d[i] 用于记录a[0...i] 的最大长度
int bsearch(const int *f, int size, const int &a)
{
    int  l=0, r=size-1;
    while( l <= r )
    {
        int  mid = (l+r)/2;
        if( a > f[mid-1] && a <= f[mid] ) return mid;// >&&<=为:>= && <
        else if( a < f[mid] ) r = mid-1;
        else l = mid+1;
    }
}
int LIS(const int *a, const int &n)
{
    int  i, j, size = 1;
    f[0] = a[0];
    d[0] = 1;
    for( i=1; i < n; ++i )
    {
        if( a[i] <= f[0] ) j = 0;                // <= 换为: <
        else if( a[i] > f[size-1] ) j = size++;// > 换为: >=
        else j = bsearch(f, size, a[i]);
        f[j] = a[i];
        d[i] = j+1;
    }
    return size;
}
void Sort(int *a,int *b,int size)
{
    int temp1,temp2;
    int i,j,flag = 1;
    for(i = 1; i <size && flag == 1; i++)
    {
        flag = 0;
        for(j = 0; j < size-i; j++)
        {
            if(a[j] > a[j+1])
            {
                flag = 1;
                temp1 = a[j];
                a[j] = a[j+1];
                a[j+1] = temp1;

                temp2=b[j];
                b[j]=b[j+1];
                b[j+1]=temp2;
            }
        }
    }
}

int main(void)
{
    int t1,t2;
    int  i, n,count=1,result=0;
    freopen("input.txt","r",stdin);
    while( scanf("%d",&n) != EOF )
    {
        int count1=0;
        memset(p,0,sizeof(p));
        memset(r,0,sizeof(r));
        for( i=0; i < n; ++i )
        {
            scanf("%d %d", &t1,&t2);
            r[t1-1]=t2;
        }
        for(i=0; i<nMax; i++)
        {

            if(r[i])
                {
                    p[count1++]=r[i];
                }
        }
        //scanf("%d %d", &p[i],&r[i]);
        //  Sort(p,r,n);
        //      for(i=0;i<n;i++)
        //         printf("%d %d",p[i],r[i]);
        result=LIS(p, n);
        if(result==1)
            printf("Case %d:\nMy King, at most %d road can be built.\n",count,result);
        else
            printf("Case %d:\nMy King, at most %d roads can be built.\n",count,result);
        // 求最大递增/ 上升子序列( 如果最大非降子序列,只需把上面的注释部分给与替换)
        count++;
    }
    fclose(stdin);
    return 0;
}
