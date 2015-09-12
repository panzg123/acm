#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int t[26],a[26],b[5],c[5],n,len,w,sum,count;
char s[27];
int cmp(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	void dfs(int k);
	int i,j,k;
	while(scanf("%d %s",&n,s)>0)
	{
		sum=count=0;
		len=strlen(s);
		s[len]='\0';
		if(len==3&&n==0&&strcmp(s,"END")==0)
			break;
		memset(a,0,sizeof(a));
		for(i=0;i<len;i++)
			t[i]=s[i]-64;
		qsort(t,len,sizeof(t[0]),cmp);
		k=0;
		w=0;
		dfs(k);
		if(w==0)
			printf("no solution");
		else
			for(i=0;i<5;i++)
			printf("%c",c[i]+64);
		printf("\n");
	}
	return 0;
}
void dfs(int k)
{
	int i;
	if(k==5&&w==0)
	{
		if(b[0]-b[1]*b[1]+b[2]*b[2]*b[2]-b[3]*b[3]*b[3]*b[3]+b[4]*b[4]*b[4]*b[4]*b[4]==n)
		{
			w=1;
			count=sum;
			for(i=0;i<5;i++)
				c[i]=b[i];

		}
	}
	else
		if(k<5)
		{
			for(i=0;i<len;i++)
				if(!a[i])
				{
					a[i]=1;
					b[k]=t[i];
					sum++;
					dfs(k+1);
					a[i]=0;

				}
		}
}
