#include <cstdio>

using namespace std;

int N;
int cost[1001][3];
int arr[1001][3];

int min (int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}

int min (int a, int b, int c) {
  if (a <= b) {
    if (c <= a)
      return c;
    else
      return a;
  }
  else { // b < a
    if (b <= c)
      return b;
    else
      return c;
  }
}

int main () {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
    cost[i][0] = arr[i][0] + min(cost[i-1][1], cost[i-1][2]);
    cost[i][1] = arr[i][1] + min(cost[i-1][0], cost[i-1][2]);
    cost[i][2] = arr[i][2] + min(cost[i-1][0], cost[i-1][1]);
  }

  printf("%d\n", min(cost[N][0], cost[N][1], cost[N][2]));

}
