#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void Map();
void Caculate(int,int);
int a[MAX]={1,2,1,2};
char b[MAX]={'S','S','E','E'};
char c[MAX][5]={{"08:10"},{"08:35"},{"10:00"},{"13:16"}};
int count=0;
float Sum=0;
int main()
{
    while(1)
    {
        int i=0;
        memset(a,0,sizeof(a));
        memset(b," ",sizeof(b));
        memset(c," ",sizeof(c));
        count=0;
        Sum=0;
        while(scanf("%d",&a[i])&&(a[i]!=-1))
        {
            scanf("%c %s",&b[i],c[i]);
            if(a[i]==0)
            {
                break;
            }
            i++;
        }
        if(a[i]==-1)
        {
            return 0;
        }
        Map();
        if(count==0)
        {
            printf("0 0\n");
            continue;
        }
        printf("%d %d\n",count,Sum/(float)count);
    }
    return 0;
}
void Map()
{
    int i,j;
    for(i=0;i<(strlen(c)/5);i++)
    {
        for(j=i+1;j<(strlen(c)/5);j++)
        {
            if((a[i]==a[j])&&(b[i]=='S')&&(b[j]=='E'))
            {
                Caculate(i,j);
            }
        }
    }
}
void Caculate(int n,int m)
{
    count++;
    char t1[3],t2[3],t3[3],t4[3];
    memcpy(t1,c[n],2);
    t1[2]='\0';
    memcpy(t2,c[n]+3,2);
    t2[2]='\0';
    memcpy(t3,c[m],2);
    t3[2]='\0';
    memcpy(t4,c[m]+3,2);
    t4[2]='\0';
//    printf("%d %s %d %s\n",atoi(t1),t2,atoi(t3),t4);
    Sum+=((atoi(t3)-atoi(t1))*60+atoi(t4)-atoi(t2));
}
