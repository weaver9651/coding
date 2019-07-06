#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int counter[10001];

void init() {
  for (int i = 0; i <= 10000; i++) {
    counter[i] = 10000;
  }
}

void dfs(int cur, int operand, int hop) {
  if (cur > 10000)
    return;
  
  if (counter[cur] > hop)
    counter[cur] = hop;
  else
    return;

  dfs(cur+operand, operand+1, hop+1);
  // reset
  dfs(cur+1, 2, hop+1);
}

int main () {
  init();
  dfs(0, 1, 0);

  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int maxx = 0;
    for (int i = x; i <= y; i++) {
      maxx = max(maxx, counter[i]);
    }

    printf("Case #%d\n%d\n", tc, maxx);
  }
  
  return 0;
}
