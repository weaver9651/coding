#include <cstdio>

using namespace std;

int arr[501][501] = {0, };
long long tot[501][501] = {0, };
int N;

void In () {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= i; j++)
      scanf("%d", &arr[i][j]);
}

long long max (long long a, long long b) {
  return a > b ? a : b;
}

long long findAns() {
  if (N == 1)
    return arr[1][1];
  tot[1][1] = arr[1][1];
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      if (j == 1) {
	tot[i][j] = tot[i-1][j] + arr[i][j];
	continue;
      }
      if (j == i) {
	tot[i][j] = tot[i-1][j-1] + arr[i][j];
	continue;
      }
      tot[i][j] = arr[i][j] + max(tot[i-1][j-1], tot[i-1][j]);
    }
  }
  long long result = 0;
  for (int i = 1; i <= N; i++) {
    result = max(result, tot[N][i]);
  }
  return result;
}

int main () {
  In();
  long long result = findAns();
  printf("%d\n", result);
  
  return 0;
}
