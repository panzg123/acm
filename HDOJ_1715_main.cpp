// Author: Tanky Woo
// HDOJ 1715
// Accepted 1715 15MS 504K 1084 B C++ Tanky Woo
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

// �����Ӵ���
// ����a���ϴ���b��ֵ����s
void big_Add_big(char a[], char b[], char s[])
{
	int m[1000], n[1000], p[1000];
	// ��ʼ��
	memset(m, 0, sizeof(m));
	memset(n, 0, sizeof(n));
	memset(p, 0, sizeof(p));
	int len_a = strlen(a);
	int len_b = strlen(b);
	// ��a���򸳸�m��������
	for(int i=0; i<len_a; ++i)
		m[i] = a[len_a-i-1]-'0';
	// ��b���򸳸�n��������
	for(int i=0; i<len_b; ++i)
		n[i] = b[len_b-i-1]-'0';
	int len = len_a>len_b? len_a: len_b;
	// �������
	for(int i=0; i<len; ++i)
		p[i] = m[i]+n[i];
	// ����
	for(int i=0; i<len; ++i)
		if(p[i] >= 10)
		{
			p[i+1] += p[i]/10;
			p[i] = p[i]%10;
		}
	// �������λ
	if(p[len]>0)
		len++;
	for(int i=0; i<len; ++i)
		s[i] = p[len-i-1]+'0';
	s[len] = 0;
}

char f[1001][300];
int main()
{

	f[1][0] = '1';   // �ȿ�ʼ��ֵ1������������룬���ģ�
	f[2][0] = '1';
	for(int i=3; i<=1000; ++i)
		big_Add_big(f[i-1], f[i-2], f[i]);
	int nNum;
	scanf("%d", &nNum);
	int n;
	for(int i=0; i<nNum; ++i)
	{
		scanf("%d", &n);
		printf("%s\n", f[n]);
	}

	return 0;

}
