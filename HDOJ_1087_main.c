//做了那道天上掉馅饼的题，觉得这道so easy
 //不过那道题一次AC，这道题却用了三次才A掉，很明显太粗心了

 #include<stdio.h>
 #include<string.h>
 #define N 1010
 int num[N];
 int rec[N];
 int main()
 {
     //freopen("input.txt","r",stdin);
     int n,max,i,j;
     while ( scanf("%d",&n)==1&&n )
     {
         for(i=0;i<n;i++)
         {
             scanf("%d",&num[i]);
         }
         memset(rec,0,sizeof(rec));
         for(i=0;i<n;i++)
         {
             max=0;
             for(j=0;j<i;j++)
             {
                 if(rec[j]>max&&num[j]<num[i])
                 {
                     max=rec[j];
                 }
             }
             rec[i]=max+num[i];
         }
         max=0;
         for(i=0;i<n;i++)
         {
             if(rec[i]>max)
                 max=rec[i];
         }
         printf("%d\n",max);
     }
     return 0;
 }
