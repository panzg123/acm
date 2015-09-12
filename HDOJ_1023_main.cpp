#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
using namespace std;
class big_int : protected string
{
//实际数字123456在内存中以字符串"654321"存放
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
    int iter_l = 0;//左操作数下标
    int iter_r = 0;//右操作数下标
    char mod = '0';//MOD 10
    char carry = '0';//满10进位
    string sum;//和
    while(iter_l < left.size() && iter_r < right.size())
        //当两个操作数都参与运算
    {
        mod = (left[iter_l] - '0' + right[iter_r] - '0' + carry - '0') % 10 + '0';
        carry = (left[iter_l] - '0' + right[iter_r] - '0' + carry - '0') / 10 + '0';
        sum += mod;
        ++iter_l;
        ++iter_r;
    }
    const big_int &rest = left.size() > right.size() ? left : right;//应用位数长的那一个操作数
    int iter_rest = iter_l;//位数更长的那个操作数的下标
    while(iter_rest < rest.size())
        //剩下一个操作数
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
//计算train排列数目的公式:
//t(n, m) = m,                      (n == 1)
//t(n, m) = t(n-1, m),              (n == m)
//t(n, m) = t(n-1, m) + t(n, m-1),  (其他情况)
{
    if(!(mat[n][m] == 0))//已经初始化的情形
        return mat[n][m];
    if(n == 1)/*以下都是未初始化的情形*/
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
