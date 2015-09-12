#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

__int64 gcd(__int64 a, __int64 b)
{
	if(a<b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

__int64 lcm(__int64 a, __int64 b)
{
	return a/gcd(a, b)*b;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int nCases;
	scanf("%d", &nCases);
	for(int i=0; i<nCases; ++i)
	{
		char tmp;
		__int64 a, b, c, d;
		scanf("%I64d/%I64d %I64d/%I64d", &a, &b, &c, &d);
		__int64 m=a*d, n=b*c, p=b*d;
		__int64 k=lcm(m, n);
		int h = gcd(k, p);
		if(p==h)
			printf("%I64d\n", k/h);
		else
			printf("%I64d/%I64d\n", k/h, p/h);
	}
	return 0;
}
