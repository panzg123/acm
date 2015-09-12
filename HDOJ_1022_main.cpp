#include<iostream>
#include<string>
using namespace std;
#define Stack_size 1050
//����ջ
typedef struct
{
    char element[Stack_size];
    int top;
}SeqStack;
//��ʼջ
void InitStack(SeqStack *s)
{
    s->top=-1;
}
//��ջ
void Push(SeqStack *s,char x)
{
    s->top++;
    s->element[s->top]=x;
}
//��ջ
char Pop(SeqStack *s,char x='x')
{
    x=s->element[s->top];
    s->top--;
    return x;
}
//ȡջ��Ԫ��
char GetTop(SeqStack *s)
{
    return s->element[s->top];
}

int main()
{
    SeqStack s;
    int n,i,j,t,N;
    while(cin>>n)
    {
        InitStack(&s);
        char *a=new char[n+1];
        char *b=new char[n+1];
        //step��¼����ջ�����
        char *step=new char[2*n+2];
        cin>>a>>b;
        t=i=j=t=N=0;
        while(j!=strlen(b))
        {
            //�ж�ջ��Ԫ���Ƿ��Ŀ��ƥ�䣬ƥ�����ջ
            if(s.top!=-1&&b[j]==GetTop(&s))
            {
                j++;
                Pop(&s);
                step[N++]=1;
                continue;
            }
            //��ƥ����Ԫ����ջ
            else if(i!=strlen(a))
            {
                Push(&s,a[i]);
                step[N++]=0;
                i++;
                continue;
            }
            //����Ԫ����ջ���в�ƥ�����Ϊ"No"
            if(i==strlen(a))
                if(b[j]!=GetTop(&s))
                {
                    t=1;
                    break;
                }
        }
        if(t==1) cout<<"No."<<endl;
        else
        {
            cout<<"Yes."<<endl;
            for(i=0;i<2*n;i++)
            {
                if(step[i]==0) cout<<"in"<<endl;
                if(step[i]==1) cout<<"out"<<endl;
            }
        }
        cout<<"FINISH"<<endl;
        delete[] step;
        delete[] a;
        delete[] b;
    }
    return 0;
}
