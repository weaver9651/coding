#include <cstdio>

using namespace std;

int leftP(int num) {
  int result = 1;
  for (int i = 1; i < num; i++) {
    result += 4*i - 2;
  }
  return result;
}

int rightP(int num) {
  int result = 1;
  for (int i = 1; i < num; i++) {
    result += 4*i + 2;
  }
  return result;
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
