#include <cstdio>

using namespace std;

int findAns(int N) {
  int **arr = new int*[N+1];
  for (int i = 0; i <= N; i++) {
    arr[i] = new int[2];
  }
  
  arr[1][0] = 0;
  arr[1][1] = 1;
  arr[2][0] = 0;
  arr[2][1] = 1;

  for (int i = 3; i <= N; i++) {
    arr[i][0] = arr[i-1][1] + arr[i-1][0];
    arr[i][1] = arr[i-1][0];
  }
  return arr[N][0]*2 + arr[N][1];
}

int main () {
  int N;
  scanf("%d", &N);
  int result = findAns(N);
  printf("%d\n", result);
  
  return 0;
}
