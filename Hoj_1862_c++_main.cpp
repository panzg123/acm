#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
const int maxn=100005;
//char f[maxn];
using namespace std;

struct Nobe
{
     char num[6];
     char name[8];
     int g;
}a[maxn];

bool cmp1(Nobe x,Nobe y)
{
     Nobe R;
     if( strcmp(x.num , y.num) > 0 )
          return 0;
     else
          return 1;
}

bool cmp2(Nobe x,Nobe y)
{
     Nobe R;
     if( strcmp(x.name , y.name) > 0 )
          return 0;
     else if(strcmp(x.name , y.name) == 0)
     {
          if( strcmp(x.num , y.num) > 0 )
               return 0;
     }
     return 1;

}

bool cmp3(Nobe x,Nobe y)
{
     Nobe R;
     if( x.g>y.g )
          return 0;
     else if(x.g==y.g)
     {
          if( strcmp(x.num , y.num) > 0 )
          return 0;
     }
     return 1;

}

int main()
{
    int n,c,q=0;
    while(scanf("%d %d",&n,&c)!=EOF &&n!=0&&c!=0)
    {
         q++;
         int i;
         for(i=0;i<n;i++)
         {
              scanf("%s%s%d",a[i].num,a[i].name,&a[i].g);
         }

         switch(c)
         {
             case 1:sort(a,a+n,cmp1);break;
             case 2:sort(a,a+n,cmp2);break;
             case 3:sort(a,a+n,cmp3);break;
         }

         printf("Case %d:\n",q);
         for(i=0;i<n;i++)
         {
               printf("%.6s %s %d\n",a[i].num ,a[i].name ,a[i].g);
         }
    }
    return 0;
}
