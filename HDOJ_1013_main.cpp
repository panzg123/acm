#include<stdio.h>
#include<string.h>
#define MAX 10000
char s[MAX];
int main()
{
	__int64 i,j;
	while(gets(s))
	{
		if(s[0]=='0')
		break;
		j=0;
		for(i=0;i<strlen(s);i++)
		{
			j+=s[i]-'0';
		}
		while(j>=10)
		{
			j=j/10+j%10;
		}
		printf("%I64d\n",j);
	}
	return 0;
}
}
