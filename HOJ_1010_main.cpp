#include<iostream>
#include<math.h>
using namespace std;
char s[10][10];
int ax,ay,bx,by,n,m,k;
int t[4][2]={1,0,-1,0,0,1,0,-1},vist[10][10],flag;
void dfs(int x,int y,int count)
{
	int i,mx,my;
	if(x==bx&&y==by)
	{
		if(k==count)
			flag=1;
		return;
	}
	if(count>=k)
		return;
	if(s[x][y]!='X')
	{
		for(i=0;i<4;i++)
		{
			mx=x+t[i][0];
			my=y+t[i][1];
			if(s[mx][my]!='X'&&mx>=1&&mx<=n&&my>=1&&my<=m&&!vist[mx][my])
			{
				vist[mx][my]=1;
				dfs(mx,my,count+1);
				vist[mx][my]=0;
				if(flag)
					return;
			}
		}
	}
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&k)>0&&(n+m+k))
	{
		int i,count;
		for(i=1;i<=n;i++)
		{
			getchar();
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&s[i][j]);
				if(s[i][j]=='S')
				{
					ax=i;
					ay=j;
				}
				if(s[i][j]=='D')
				{
					bx=i;
					by=j;
				}
			}
		}
		getchar();
		memset(vist,0,sizeof(vist));
		if(abs(ax-bx)+abs(ay-by)>k||(ax+bx+ay+by+k)%2==1)
		{
			printf("NO\n");
			continue;
		}
		vist[ax][ay]=1;
		flag=0;
		count=0;
		dfs(ax,ay,count);
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
