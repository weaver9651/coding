#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int Map[100001];
bool visit[100001] = {false, };

const int width = 100000;

int bfs(int N, int K) {
  queue<int> q;
  q.push(N);
  visit[N] = true;
  Map[N] = 0;
    
  int cur, tmp;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    if (cur == K)
      return Map[K];

    tmp = cur-1;
    if (tmp >= 0 && tmp <= width && !visit[tmp]) {
      q.push(tmp);
      visit[tmp] = true;
      Map[tmp] = Map[cur] + 1;
    }
    tmp = cur+1;
    if (tmp >= 0 && tmp <= width && !visit[tmp]) {
      q.push(tmp);
      visit[tmp] = true;
      Map[tmp] = Map[cur] + 1;
    }
    tmp = 2*cur;
    if (tmp >= 0 && tmp <= width && !visit[tmp]) {
      q.push(tmp);
      visit[tmp] = true;
      Map[tmp] = Map[cur] + 1;
    }
  }
}

int main () {
  int N, K;
  cin >> N >> K;
  printf("%d\n", bfs(N, K));
  
  return 0;
}
