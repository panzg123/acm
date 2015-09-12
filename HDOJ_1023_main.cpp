#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
class big_int : protected string
{
//ʵ������123456���ڴ������ַ���"654321"���
    friend ostream &operator <<(ostream &os, const big_int &right);
    friend big_int operator +(const big_int &left, const big_int &right);
    friend bool operator ==(const big_int &left, int right);
public:
    big_int &operator =(int right);
    big_int(int r)
    {
        operator =(r);
    }
    big_int(const string &r):
        string(r) {}
    big_int():
        string("0") {}
};
ostream &operator <<(ostream &os, const big_int &right)
{
    int i = right.size();
    while(i > 0)
    {
        --i;
        os << right[i];
    }
    return os;
}
big_int operator +(const big_int &left, const big_int &right)
{
    int iter_l = 0;//��������±�
    int iter_r = 0;//�Ҳ������±�
    char mod = '0';//MOD 10
    char carry = '0';//��10��λ
    string sum;//��
    while(iter_l < left.size() && iter_r < right.size())
        //����������������������
    {
        mod = (left[iter_l] - '0' + right[iter_r] - '0' + carry - '0') % 10 + '0';
        carry = (left[iter_l] - '0' + right[iter_r] - '0' + carry - '0') / 10 + '0';
        sum += mod;
        ++iter_l;
        ++iter_r;
    }
    const big_int &rest = left.size() > right.size() ? left : right;//Ӧ��λ��������һ��������
    int iter_rest = iter_l;//λ���������Ǹ����������±�
    while(iter_rest < rest.size())
        //ʣ��һ��������
    {
        mod = (rest[iter_rest] - '0' + carry - '0') % 10 + '0';
        carry = (rest[iter_rest] - '0' + carry - '0') / 10 + '0';
        sum += mod;
        ++iter_rest;
    }
    if(carry != '0')
    {
        sum += carry;
    }
    return sum;
}
bool operator ==(const big_int &left, int right)
{
    return dynamic_cast<const string&>(left) ==
           static_cast<string>(big_int(right));
}
big_int &big_int::operator =(int right)
{
    char str[20];
    itoa(right, str, 10);
    reverse(str, str + strlen(str));
    string::operator =(str);
    return *this;
}
big_int mat[101][101];
big_int &t(int n, int m)
//����train������Ŀ�Ĺ�ʽ:
//t(n, m) = m,                      (n == 1)
//t(n, m) = t(n-1, m),              (n == m)
//t(n, m) = t(n-1, m) + t(n, m-1),  (�������)
{
    if(!(mat[n][m] == 0))//�Ѿ���ʼ��������
        return mat[n][m];
    if(n == 1)/*���¶���δ��ʼ��������*/
        return mat[n][m] = m;
    if(n == m)
        return mat[n][m] = t(n - 1, m);
    return mat[n][m] = t(n - 1, m) + t(n, m - 1);
}
int main()
{
    int n;
    while(cin >> n)
        cout << t(n, n) << '\n';
    return 0;
}
