#include<iostream>
using namespace std;
//求最大公约数
int gcd(int x,int y){
    if(x==y) return x;
    else if(x>y) return gcd(x-y,y);
    else return gcd(y-x,x);
}
int main(){
    int p,q;
    while(cin>>p>>q)
        cout<<p+q-gcd(p,q)<<endl;
    return 0;
}
