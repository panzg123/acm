#include <iostream>
#define MAX 1000010
using namespace std;
int w[2][MAX];
int dp[MAX];
int a[MAX];
int sum[MAX];

inline int max(int a, int b) {
  return a > b ? a : b;
}
int main() {
  int m, n, c;
  while (scanf("%d%d", &m, &n) > 0) {
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum[i] = sum[i-1] + a[i];
      w[0][i] = 0;
    }
    int t = 1;
    for (int i = 1; i <= m; ++i) {
      w[t][i] = dp[i] = sum[i];
      for (int j = i+1; j <= n-m+i; ++j) {
        dp[j] = max(dp[j-1], w[1-t][j-1]) + a[j];
        w[t][j] = max(dp[j], w[t][j-1]);
      }
      t = 1 - t;
    }
    printf("%d\n", w[m%2][n]); //����w�˻��ˣ�û��w[m][n]���m%2���Ա�ʾ��m�Σ��������m = 1,��2���Ա�֪����
  }
  return 0;
}
