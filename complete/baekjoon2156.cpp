#include <cstdio>

using namespace std;

int arr[10001] = {0, };
int tot[10001] = {0, };
int N;

int max(int a, int b) {
  return a > b ? a : b;
}
int max(int a, int b, int c) {
  return max(a, max(b, c));
}

int findAns() {
  tot[1] = arr[1];
  if (N == 1)
    return tot[1];
  tot[2] = arr[1] + arr[2];
  if (N == 2)
    return tot[2];

  for (int i = 3; i <= N; i++) {
    tot[i] = max(tot[i-3] + arr[i-1] + arr[i],
		 tot[i-2] + arr[i],
		 tot[i-1]);
  }
  return tot[N];
}

int main () {
  scanf("%d", &N);
  arr[0] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &arr[i]);
  }

  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
