#include <cstdio>
#include <deque>
#include <algorithm>

using namespace std;

int N;
int arr[10000] = {0,};

void In() {
  scanf("%d", &N);
  int tmp;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    arr[i] = tmp;
  }
}

int findAns() {
  int maxx = 0;
  sort(arr, arr+N);
  deque<int> dq;
  for (int i = 0; i < N; i++) {
    if (i % 2)
      dq.push_front(arr[i]);
    else
      dq.push_back(arr[i]);
  }
  for (int i = 0, j = 1; j < N; i++, j++) {
    maxx = max(maxx, abs(dq[i]-dq[j]));
  }
  maxx = max(maxx, abs(dq[0]-dq[N-1]));
  return maxx;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    In();
    int result = findAns();
    printf("#%d %d\n", tc, result);
  }
  
  return 0;
}
