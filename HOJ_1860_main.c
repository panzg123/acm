#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5]={0};
    char s1[5];
    char s2[80];
    char *ptr;
    int i;
    while(1)
    {
        memset(a,0,sizeof(a));
        gets(s1);
        if(strcmp(s1,"#")==0)
           break;
        gets(s2);
        for(i=0;i<strlen(s1);i++)
        {
            ptr=strchr(s2,s1[i]);
            while(ptr!=NULL)
            {
                a[i]++;
                ptr=strchr(ptr+1,s1[i]);
            }
        }
        for(i=0;i<strlen(s1);i++)
            printf("%c %d\n",s1[i],a[i]);
    }
    return 0;
}
