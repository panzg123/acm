/* C语言 HOJ_1862 讨论
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student
{
    int num;
    char name[10];
    int score;
}Stu;
Stu stu[100010];
int cmp1(const void *a,const void *b)
{
    return (*(Stu *)a).num>(*(Stu *)b).num?1:-1;
}
int cmp2(const void *a,const void *b)
{
    if(strcmp((*(Stu *)a).name,(*(Stu *)b).name)==0)
    {
        return (*(Stu *)a).num>(*(Stu *)b).num?1:-1;
    }
    return strcmp((*(Stu *)a).name,(*(Stu *)b).name)>0?1:-1;
}
int cmp3(const void *a,const void *b)
{
    if((*(Stu *)a).score==(*(Stu *)b).score)
    {
        return (*(Stu *)a).num>(*(Stu *)b).num?1:-1;
    }
    return (*(Stu *)a).score>(*(Stu *)b).score?1:-1;
}
int main()
{
    int n,c,i,k=0;
    while(scanf("%d %d",&n,&c)&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d %s %d",&stu[i].num,stu[i].name,&stu[i].score);
        if(c==1)
        {
            qsort(stu,i,sizeof(Stu),cmp1);
        }
        else if(c==2)
        {
            qsort(stu,i,sizeof(Stu),cmp2);
        }
        else
        {
            qsort(stu,i,sizeof(Stu),cmp3);
        }
        printf("Case %d:\n",++k);
        for(i=0;i<n;i++)
            printf("%06d %s %d\n",stu[i].num,stu[i].name,stu[i].score);
    }
    return 0;
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    int number;
    char name[9];
    int score;
}Student;
Student stu[100001];
//按照学号比较
int cmp1( const void *a,const void *b)
{
    Student *p1=(Student *)a;
    Student *p2=(Student *)b;
    return ((*p1).number>(*p2).number)?1:-1;
}
//按照姓名字典非递减排序
int cmp2(const void *a,const void *b)
{
    Student *p1=(Student *)a;
    Student *p2=(Student *)b;
    if(strcmp((*p1).name,(*p2).name)==0)
    {
        return ((*p1).number>(*p2).number)?1:-1;
    }
    return (strcmp((*p1).name,(*p2).name)>0)?1:-1;
}
//按照分数非递减排序
int cmp3(const void *a,const void *b)
{
    Student *p1=(Student *)a;
    Student *p2=(Student *)b;
    if((*p1).score==(*p2).score)
    {
         return ((*p1).number>(*p2).number)?1:-1;
    }
    return ((*p1).score>(*p2).score)?1:-1;
}
int main()
{
    int N,C,i,k=1;
    while(scanf("%d %d",&N,&C)&&N)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d %s %d",&stu[i].number,stu[i].name,&stu[i].score);
        }
        if(C==1)
        {
            qsort(stu,N,sizeof(Student),cmp1);
        }
        else if(C==2)
        {
            qsort(stu,N,sizeof(Student),cmp2);
        }
        else
        {
            qsort(stu,N,sizeof(Student),cmp3);
        }
        printf("Case %d:\n",k++);
        for(i=0;i<N;i++)
            printf("%06d %s %d\n",stu[i].number,stu[i].name,stu[i].score);
    }
    return 0;
}

