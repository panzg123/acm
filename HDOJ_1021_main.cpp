#include<stdio.h>
#define MAX 1000000
__int64 s[MAX];
int main()
{
	__int64 n,i,j;
	while(scanf("%I64d",&n)!=EOF)
	{
		s[0]=7%3;
		s[1]=11%3;
		for(i=2;i<=n;i++)
		{
			s[i]=(s[i-1]+s[i-2])%3;
		}
		if(s[n]==0)
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
