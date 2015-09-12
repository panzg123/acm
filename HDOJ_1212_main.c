//ДѓЪ§ШЁгр
#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    long a[1000],i,t,m,n,r;
    while(scanf("%s%ld",s,&n)>0)
    {
        m=strlen(s);
        for(i=0; i<m; i++)
            a[i]=s[i]-48;
        r=0;
        for(i=0; i<m; i++)
        {
            t=r*10+a[i];
            a[i]=t/n;
            r=t%n;
        }
        printf("%ld\n",r);
    }
    return 0;
}
