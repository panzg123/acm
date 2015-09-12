//1016
#include <iostream>
#include <vector>
using namespace std;
int result[20];//��ż���Ľ��
vector< vector<int> > results;
int n;
//int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37};//����13��40���ڵ�����
bool prime[] = {0,0 ,1 ,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1};

bool isPrime(int num)
{
    return prime[num];
}

bool isIn(int list[], int len, int num)
{
    for (int i = 0; i < len; ++ i)
        if (list[i] == num)
            return true;
    return false;
}

void findCircle(int i)
{
    int count =0;
    for (int j = 2; j <= n; ++ j)
        if (!isIn(result,i,j) && isPrime(result[i-1] + j))
        {
            result[i] = j;
            count ++;
            findCircle(i + 1);
        }
    if (count == 0)
        return;
    if (i == n - 1 && isPrime(1 + result[n - 1]))
    {

        vector<int > temp ;
        for (int k = 0; k < n ; ++ k)
            temp.push_back(result[k]);

        results.push_back(temp);
    }
}

int main()
{

    int Case = 0;
    while(cin >> n)
    {

        Case ++;
        results.clear();
        result[0] = 1;
        findCircle(1);

        cout << "Case "<<Case<<":"<<endl;
        for (int i = 0; i < results.size(); ++ i )
        {
            cout << results[i][0]<< " ";

            for (int j = 1; j < results[i].size() - 1; ++ j)
                cout << results[i][j]<< " ";
            cout << results[i][results[i].size() - 1] ;//�����ر�ע�⣬���һ��������ո�
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
