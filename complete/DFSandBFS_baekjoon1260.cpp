#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

bool Map[1001][1001] = {false, };
bool visit[1001] = {false, };
int N, M, V;

void bfs(int start) {
  queue<int> q;
  q.push(start);
  visit[start] = true;

  int cur_node;
  while(!q.empty()) {
    cur_node = q.front();
    q.pop();

    cout << cur_node << " ";

    for (int i = 1; i <= N; i++) {
      if (!visit[i] && Map[cur_node][i]) {
	visit[i] = true;
	q.push(i);
      }
    }
  }
  cout << endl;
}

void dfs(int node) {
  visit[node] = true;
  cout << node << " ";
  for (int i = 1; i <= N; i++) {
    if (node == i)
      continue;
    if (!visit[i] && Map[node][i]) {
      dfs(i);
    }
  }
}

void init() {
  for (int i = 1; i <= N; i++) {
    visit[i] = false;
  }
}

int main () {
  cin >> N >> M >> V;

  int y, x;
  for (int m = 0; m < M; m++) {
    scanf("%d", &y);
    scanf("%d", &x);
    Map[y][x] = true;
    Map[x][y] = true;
  }

  dfs(V);
  cout << endl;
  init();
  bfs(V);

  return 0;
}
