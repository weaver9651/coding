#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int N, M;
int Map[100][100];
bool visit[100][100];
int date[100][100];

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void In() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &Map[i][j]);
    }
  }
}

bool isInside(int y, int x) {
  if (y < N && y >= 0 && x < M && x >= 0)
    return true;
  else
    return false;
}

int bfs(int start_y, int start_x) {
  queue<pair<int, int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;
  date[start_y][start_x] = 1;

  int cur_y, cur_x;
  int tmp_y, tmp_x;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == 1) {
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	date[tmp_y][tmp_x] = date[cur_y][cur_x] + 1;
      }
    }
  }

  return date[N - 1][M - 1];
}

int main() {
  In();
  cout << bfs(0, 0) << endl;

  return 0;
}
