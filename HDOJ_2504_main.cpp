#include <iostream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <string>
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

__int64 a, b, c;
int nCases;
int main()
{
    scanf("%d", &nCases);
    while(nCases--)
    {
        scanf("%I64d %I64d", &a, &b);
        __int64 k=a/b;
        for(int i=2; ; ++i)
            if(gcd(k, i) == 1)
            {
                printf("%I64d\n", i*b);
                break;
            }
    }
    return 0;
}
