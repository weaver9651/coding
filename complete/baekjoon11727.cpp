#include <cstdio>

using namespace std;

int findAns(int N) {
  int arr[1001] = {0,};
  arr[1] = 1;
  arr[2] = 3;
  if (N < 3)
    return arr[N];
  for (int i = 3; i <= N; i++) {
    arr[i] = ((arr[i-1] % 10007)+ (arr[i-2]*2 % 10007)) % 10007;
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
