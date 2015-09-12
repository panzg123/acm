#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    int n,i=0,count;
    string s,res="",temp="";
    char temp1[10]="";
    while(cin>>n&&n!=0)
    {
        while(n--)
        {
            i=0,count=1;
            res.clear();
            cin>>s;
            while(i<s.length())
            {
                count=1;
                while(s[i]==s[i+1])
                {
                    i++;
                    count++;
                }
                if(count!=1)
                {
                    itoa(count,temp1,10);
                    temp=temp1;
                    res.append(temp);
                }
        //        cout<<temp<<endl;
                res.push_back(s[i]);
                i++;
            }
            cout<<res<<endl;
        }
    }
    return 0;
}
