#include <cstdio>

using namespace std;

int findAns(int N) {
  int result = 0;
  int tmp;
  for (int i = 1; i <= N / 2; i++) {
    tmp = 0;
    for (int j = i; j <= N / 2 + 1; j++) {
      tmp += j;
      if (tmp > N)
	break;
      else if (tmp == N) {
	result++;
	break;
      }
    }
  }
  
  return result + 1;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    int N;
    scanf("%d", &N);

    int result = findAns(N);
    printf("#%d %d\n", tc+1, result);
  }
  
  return 0;
}
