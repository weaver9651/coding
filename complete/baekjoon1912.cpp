#include <cstdio>

using namespace std;

int max(int a, int b) {
  return a > b ? a : b;
}

int main () {
  int N;
  scanf("%d", &N);
  int *tot = new int[N+1];
  tot[0] = -1001;
  int maxx = -1001;
  int tmp;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &tmp);
    if (tmp < tot[i-1] + tmp) {
      tot[i] = tmp + tot[i-1];
    }
    else {
      tot[i] = tmp;
    }
    maxx = max(maxx, tot[i]);
  }
  printf("%d\n", maxx);
  
  return 0;
}

