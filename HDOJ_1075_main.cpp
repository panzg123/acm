#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,string>M;
int main()
{
    string a,b;
    cin>>a;//"START"
    while(cin>>a && a!="END")
    {
        cin>>b;
        M[b] = a;
    }
    cin>>a;//"START"
    getchar();//吃回车
    char tmp[3005];
    while(1)
    {
        gets(tmp);//用这个比getline()强
        if(strcmp(tmp,"END") == 0 )
            break;
        int i,len;
        len = strlen(tmp);
        b = "";
        for(i=0; i<len; i++)
        {
            if(!(tmp[i]>='a' && tmp[i]<='z'))//非小写字母
            {
                if(M[b]!="")//存在这个单词
                    cout<<M[b];
                else
                    cout<<b;
                b="";
                cout<<tmp[i];
            }
            else //小写字母
                b+=tmp[i];
        }
        cout<<endl;
    }
    return 0;
}
