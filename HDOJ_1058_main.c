#include <stdio.h>
#include <stdlib.h>

#define N 6000
__int64 res[N];
int t=0;
void Caculate(void);
__int64  Min(__int64,__int64,__int64,__int64,int*);
int main()
{
	Caculate();
	while (scanf("%d",&t)!=EOF&&t!=0)
	{
		if(t%10==1&&t%100!=11)
			printf("The %dst humble number is ",t);
		else if(t%10==2&&t%100!=12)
			printf("The %dnd humble number is ",t);
		else if(t%10==3&&t%100!=13)
			printf("The %drd humble number is ",t);
		else
			printf("The %dth humble number is ",t);
		printf("%d.\n",res[t]);
	}
    return 0;
}
void Caculate()
{
    int i=1,j=1,m=1,k=1,n;
    int flag=0;
    res[1]=1;
    for(n=2;n<=5842;)
    {

        __int64 result = Min(2*res[i],3*res[j],5*res[m],7*res[k],&flag);
		if (result>res[n-1])
		{
			res[n]=result;
			n++;
		}
        switch(flag)
        {
		case 1:
			{
				i++;
				break;
			}
		case 2:
            {
				j++;
				break;
            }
		case 3:
            {
				m++;
				break;
            }
		case 4:
            {
				k++;
				break;
            }
        }
    }
}
__int64 Min(__int64 a,__int64 b,__int64 c,__int64 d,int *flag)
{
    __int64 min=2000000009;
    if(a<min)
    {
        min=a;
        *flag=1;
    }
    if(b<min)
    {
        min=b;
        *flag=2;
    }
    if(c<min)
    {
        min=c;
        *flag=3;
    }
    if(d<min)
    {
        min=d;
        *flag=4;
    }
    return min;
}
