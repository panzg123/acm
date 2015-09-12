//纯粹的数学题
#include<iostream>
using namespace std;

int main()
{
	int num,sum;
	while(scanf("%d",&num)!=EOF)
	{
		sum=num*num*num*(num*num*num-1)/2-3*num*num*(num-1);
		cout<<sum<<endl;
	}
	return 0;
}
