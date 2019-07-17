#include <cstdio>

using namespace std;

/*
집 수
R G B 비용
*/

int N;
int arr[1000][3];
int cost[1000];
int color[1000];

int min(int a, int b) {
  return a < b ? a : b;
}

int min (int a, int b, int c) {
  return a < b ? a < c ? a : c : b < c ? b : c; 
}

int rmin(int c, int i) {
  if (c == 0)
    return min(arr[i][1], arr[i][2]);
  else if (c == 1)
    return min(arr[i][0], arr[i][2]);
  else
    return min(arr[i][0], arr[i][1]);
}

void In() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", &arr[i][0], &arr[i][1], &arr[i][2]);
  }
}

int findMin() {
  cost[0] = min(arr[0][0], arr[0][1], arr[0][2]);
  color[0] = cost[0] == arr[0][0] ? 0 : cost[0] == arr[0][1] ? 1 : 2;
  if (N == 1)
    return cost[0];

  cost[1] = min(arr[0][0] + rmin(0, 1),
		arr[0][1] + rmin(1, 1),
		arr[0][2] + rmin(2, 1));
  color[1] = cost[1] == arr[0][0] + rmin(0, 1) ? 0 : cost[1] == arr[0][1] + rmin(1, 1) ? 1 : 2;
  if (N == 2)
    return cost[1];
  
  for (int i = 2; i < N; i++) {
    cost[i] = cost[i-2] + min(arr[i-1][0] + rmin(0, i),
			      arr[i-1][1] + rmin(1, i),
			      arr[i-1][2] + rmin(2, i));
    color[i] =
      cost[i] - cost[i-1] == arr[i-1][0] + rmin(0, i) ? 0 :
      cost[i] - cost[i-1] == arr[i-1][1] + rmin(1, i) ? 1 : 2;
  }
  return cost[N-1];
}

int main () {
  In();
  int result = findMin();
  printf("%d\n", result);

  
  return 0;
}
