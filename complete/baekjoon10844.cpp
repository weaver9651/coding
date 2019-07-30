#include <cstdio>

#define DD 1000000000

using namespace std;

long long findAns(int N) {
  long long result = 0;
  long long arr[N+1][10];
  arr[1][0] = 0;
  for (int i = 1; i <= 9; i++)
    arr[1][i] = 1;
  if (N == 1)
    return 9;
  
  for (int i = 2; i <= N; i++) {
    arr[i][0] = arr[i-1][1];
    for (int j = 1; j < 9; j++)
      arr[i][j] = arr[i-1][j-1] % DD + arr[i-1][j+1] % DD;
    arr[i][9] = arr[i-1][8];
  }

  for (int i = 0; i <= 9; i++) {
    result = arr[N][i] + result % DD;
  }
  
  return result % DD;
}

int main () {
  int N;
  scanf("%d", &N);
  printf("%lld\n", findAns(N));
  
  return 0;
}
