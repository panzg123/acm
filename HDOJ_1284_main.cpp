/*
Anthor:wutianqi
Ä¸º¯Êý£¬Ä£°å
*/
#include <iostream>
using namespace std;

int c1[32768], c2[32768] = {0};
int main()
{
    int i, j, k, h;

    for (i = 0; i <= 32767; i++)
        c1[i] = 1;
    for (i = 2; i <= 3; i++)
    {
        for (j = 0; j <= 32767; j++)
        {
            for (k = 0; k + j <= 32767; k += i)
            {
                c2[k + j] += c1[j];
            }
        }
        for (h = 0; h <= 32767; h++)
        {
            c1[h] = c2[h];
            c2[h] = 0;
        }
    }

    int n;
    while (scanf("%d", &n) != EOF)
        printf("%d\n", c1[n]);

    return 0;
}
