#include <cstdio>

using namespace std;

int gcd(int a, int b) {
  int little, big;
  if (a >= b) {
    big = a;
    little = b;
  }
  else {
    big = b;
    little = a;
  }
  
  while (big != little) {
    big -= little;
    if (big < little) {
      int tmp = big;
      big = little;
      little = tmp;
    }
  }
  return big;
}

int cutdown(int N, int K) {
  int tmp;
  int result = 1;
  if (K < 10) {
    tmp = N % K;
    if (tmp) {
      return tmp; 
    }
    else {
      return K;
    }
  }
  
  for (int i = 1; i <= N; i++) {
    result *= i;
    tmp = result % K;
    if (tmp)
      result = tmp;
    else
      result = K;
  }
  
  return result;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    int N, K;
    scanf("%d%d", &N, &K);

    N = cutdown(N, K);
    printf("#%d %d\n", tc+1, gcd(N, K));
  }

  return 0;  
}
