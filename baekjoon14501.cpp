#include <cstdio>

using namespace std;

int N;
int tot[17] = {0, };
int T[17] = {0, };
int P[17] = {0, };

int max (int a, int b) {
  return a > b ? a : b;
}

void In() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d", &T[i], &P[i]);
  }
}

int findAns() {
  for (int i = 1; i <= N+1; i++) {
    tot[i] = max(tot[i], tot[i-1]);
    if (i + T[i] > N+1)
      continue;
    tot[i+T[i]] = max(tot[i+T[i]], tot[i] + P[i]);
  }
  return tot[N+1];
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  
  return 0;
}
