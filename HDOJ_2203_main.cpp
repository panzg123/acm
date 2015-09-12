#include<iostream>
#include<string>
using namespace std;
int main(){
    string f,s;
    while(cin>>f>>s){
        f+=f;
        if(f.find(s)<f.size())cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
