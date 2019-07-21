#include <cstdio>

using namespace std;

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int N, Q;
    scanf("%d%d", &N, &Q);

    int **arr = new int*[N];
    for (int i = 0; i < N; i++) {
      arr[i] = new int[4];
      for (int j = 0; j < 4; j++) {
	arr[i][j] = 0;
      }
    }
    
    int tmp;
    for (int i = 0; i < N; i++) {
      scanf("%d", &tmp);
      arr[i][tmp]++;

      if (i == 0)
	continue;
      
      arr[i][1] += arr[i-1][1];
      arr[i][2] += arr[i-1][2];
      arr[i][3] += arr[i-1][3];
    }

    int a, b;
    int num1, num2, num3;
    printf("#%d\n", tc);
    for (int i = 0; i < Q; i++) {
      scanf("%d%d", &a, &b);
      a--;
      b--;

      if (a == 0) {
	num1 = arr[b][1];
	num2 = arr[b][2];
	num3 = arr[b][3];
      }
      else {
	num1 = arr[b][1] - arr[a-1][1];
	num2 = arr[b][2] - arr[a-1][2];
	num3 = arr[b][3] - arr[a-1][3];
      }
            
      printf("%d %d %d\n", num1, num2, num3);
    }
  }
  return 0;
}
