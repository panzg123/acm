#include<stdio.h>
#include<math.h>
int main()
{
	int n,m;
	int zx[2],yx[2];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int min=n<m?n:m;
		int max=n>m?n:m;
		int a=(int )pow((double)min,0.5);
		if(a*a<min)
			a++;
		zx[0]=(min-(a-1)*(a-1)-1)/2;
		yx[0]=(min-(a-1)*(a-1))/2;
		int b=(int )pow((double)max,0.5);
		if(b*b<max)
			b++;
		zx[1]=(max-(b-1)*(b-1)-1)/2;
		yx[1]=(max-(b-1)*(b-1))/2;
		int aa=yx[0]+b-a-yx[1]>0?yx[0]+b-a-yx[1]:yx[1]-(yx[0]+b-a);
		int bb=zx[1]>zx[0]?zx[1]-zx[0]:zx[0]-zx[1];
		printf("%d\n",aa+bb+b-a);
	}
	return 0;
}
