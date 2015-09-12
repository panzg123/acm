//×Ö·û´®·Ö¸î
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=1009;

char str[maxn];
int a[maxn];
char *p;
int n;
int i;

int main()
{
	while(cin >> str)
	{
		p=strtok(str,"5");
		n=0;

		while(p)
		{
			sscanf(p,"%d",&a[++n]);
			p=strtok(NULL,"5");
		}
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++)
		{
			if(i!=1)
				cout << ' ';
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
