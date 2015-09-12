#include<stdio.h>
int main()
{
	int m,n,x1,y1,x2,y2;
	while(scanf("%ld %ld",&m,&n)&&(m||n))
	{
		x1=x2=m;
		y1=y2=n;
		while(scanf("%ld %ld",&m,&n)&&(m||n))
		{
			if(x1<m) x1=m;
			if(y1<n) y1=n;
			if(y2>n) y2=n;
			if(x2>m) x2=m;
		}
		printf("%d %d %d %d\n",x2,y2,x1,y1);
	}
	return 0;
}
