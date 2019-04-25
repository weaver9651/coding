#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

bool Map[101][101] = { false, };
bool visit[101] = { false, };

int N, E;

void In() {
  int y, x;
  cin >> N >> E;
  for (int i = 0; i < E; i++) {
    scanf("%d", &y);
    scanf("%d", &x);
    Map[y][x] = true;
    Map[x][y] = true;
  }
}

void bfs() {
  queue<int> q;
  q.push(1);
  visit[1] = true;

  int cur_loc;
  int tmp_loc;

  while (!q.empty()) {
    cur_loc = q.front();
    q.pop();

    for (int i = 1; i <= N; i++) {
      if (i == cur_loc)
	continue;
      if (Map[cur_loc][i] && !visit[i]) {
	q.push(i);
	visit[i] = true;
      }
    }
  }
}

int taint() {
  int counter = 0;
  for (int i = 1; i <= N; i++) {
    if (visit[i])
      counter++;
  }
  return counter;
}

int main() {
  In();
  bfs();
  cout << taint() - 1 << endl;

  return 0;
}
