#include <iostream>
#include <cmath>
using namespace std;

int nCases;
int num1, num2;

bool Is_perfectNum(int n)
{
    int sum=0;
    for(int i=1; i<=n/2; ++i)
        if(n%i == 0)
            sum += i;
    if(sum == n)
        return 1;
    else
        return 0;
}

int main()
{
    int cnt;
    scanf("%d", &nCases);
    while(nCases--)
    {
        scanf("%d %d", &num1, &num2);
        if(num1 > num2)
        {
            num1 ^= num2;
            num2 ^= num1;
            num1 ^= num2;
        }
        cnt = 0;
        for(int i=num1; i<=num2; ++i)
            if(Is_perfectNum(i))
                cnt++;
        printf("%d\n", cnt);

    }
    return 0;
}
