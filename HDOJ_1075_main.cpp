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
    getchar();//�Իس�
    char tmp[3005];
    while(1)
    {
        gets(tmp);//�������getline()ǿ
        if(strcmp(tmp,"END") == 0 )
            break;
        int i,len;
        len = strlen(tmp);
        b = "";
        for(i=0; i<len; i++)
        {
            if(!(tmp[i]>='a' && tmp[i]<='z'))//��Сд��ĸ
            {
                if(M[b]!="")//�����������
                    cout<<M[b];
                else
                    cout<<b;
                b="";
                cout<<tmp[i];
            }
            else //Сд��ĸ
                b+=tmp[i];
        }
        cout<<endl;
    }
    return 0;
}
