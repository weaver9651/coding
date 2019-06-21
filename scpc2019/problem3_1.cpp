#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10001] = {false, };
int counter[10001];
// cur, operand, hop
vector<pair<int, int> > q;

bool isInside(int num) {
  if (num >= 0 && num <= 10000)
    return true;
  else
    return false;
}

void bfs() {
  int maxx = 0;
  int sizee;
  q.push_back(make_pair(0, 1));
  visit[0] = true;
  int cur, tmp, operand, hop;

  while (!q.empty()) {
    sizee = q.size();
    maxx = max(maxx, sizee);
    cur = q.back().first;
    operand = q.back().second;
    
    q.pop_back();

    tmp = cur + 1;
    if (isInside(tmp) && !visit[tmp]) {
      q.push_back(make_pair(tmp, 2));
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }

    tmp = cur + operand;
    if (isInside(tmp) && !visit[tmp]) {
      q.push_back(make_pair(tmp, operand+1));
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }
    
  }
  cout << maxx << endl;
}

void init() {
  for (int i = 1; i <= 10000; i++) {
    counter[i] = 10000;
  }
}

int main () {
  q.reserve(160);
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
