#include <cstdio>

using namespace std;

int leftP(int n) {
  return 2*n*n - 4*n + 3;
}

int rightP(int n) {
  return 2*n*n - 1;
}

int main () {
  int T, N;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    printf("#%d %d %d\n", tc, leftP(N), rightP(N));
  }
  
  return 0;
}
