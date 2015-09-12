// HOJ_1860.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX 4
void Map();
void Caculate(int,int);
int a[MAX]={1,2,1,2};
char b[MAX]={'S','S','E','E'};
char c[MAX][5]={{"08:10"},{"08:35"},{"10:00"},{"13:16"}};
int count=0;
float Sum=0;
int main()
{
    Map();
    printf("%d %f",count,Sum/(float)count);
    return 0;
}
void Map()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
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
    char t1[2],t2[2],t3[2],t4[2];
    memcpy(t1,c[n],2);
    memcpy(t2,c[n]+2,2);
    memcpy(t3,c[m],2);
    memcpy(t4,c[m]+2,2);
    Sum+=((atoi(t3)-atoi(t1))*60+atoi(t4)-atoi(t2));
}
