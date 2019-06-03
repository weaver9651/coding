#include <cstdio>

using namespace std;

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int N, Q;
    scanf("%d%d", &N, &Q);

    int *arr = new int[N];
    int tmp;
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
    }

    int a, b;
    int num1, num2, num3;
    printf("#%d\n", tc);
    for (int i = 0; i < Q; i++) {
      scanf("%d%d", &a, &b);
      num1 = 0, num2 = 0, num3 = 0;
      for (int j = a-1; j <= b-1; j++) {
	switch(arr[j]) {
	case 1:
	  num1++;
	  break;
	case 2:
	  num2++;
	  break;
	case 3:
	  num3++;
	  break;
	}
      }
      printf("%d %d %d\n", num1, num2, num3);
    }
  }
  return 0;
}
