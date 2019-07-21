#include <cstdio>

using namespace std;

int findAns(int N) {
  int *arr = new int[N+1];
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= N; i++) {
    arr[i] = (arr[i-1] + arr[i-2]) % 10007;
  }
  return arr[N];
}

int main () {
  int N;
  scanf("%d", &N);
  int result = findAns(N);
  printf("%d\n", result);
  
  return 0;
}
