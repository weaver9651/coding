#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int X, Y;
bool visit[10001] = {false, };
int counter[10001];
// cur, operand, hop
queue<pair<int, pair<int, int> > > q;

bool isInside(int num) {
  if (num >= 0 && num <= 10000)
    return true;
  else
    return false;
}

void bfs() {
  q.push(make_pair(0, make_pair(1, 0)));
  visit[0] = true;
  int cur, tmp, operand, hop;

  while (!q.empty()) {
    cur = q.front().first;
    operand = q.front().second.first;
    hop = q.front().second.second;
    
    q.pop();

    tmp = cur + operand;
    if (isInside(tmp) && !visit[tmp]) {
      q.push(make_pair(tmp, make_pair(operand+1, hop+1)));
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }
    
    tmp = cur + 1;
    if (isInside(tmp) && !visit[tmp]) {
      q.push(make_pair(tmp, make_pair(2, hop+1)));
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }
  }
}

void init() {
  for (int i = 1; i <= 10000; i++) {
    counter[i] = 10000;
  }
}

int main () {
  init();
  bfs();

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
