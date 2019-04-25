#pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int Map[1000][1000];
int N, M;
int state;
int maxx;
int date[1000][1000];
bool visit[1000][1000] = { false, };
queue<pair<int, int> > q;

int dy[] = { 0, 0, 1, -1 };
int dx[] = {1, -1, 0, 0};

void In() {
  cin >> M >> N;
  int counter = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &Map[i][j]);
      if (Map[i][j] == 0)
	counter++;
      else if (Map[i][j] == 1) {
	q.push(make_pair(i, j));
	visit[i][j] = true;
	date[i][j] = 0;
      }
    }
  }

  // 다 익음
  if (counter == 0) {
    state = 0;
  }
  else {
    state = 1;
  }
}

void check() {
  if (state == 0)
    return;
  else {
    int maxx = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	maxx = max(maxx, date[i][j]);
	if (Map[i][j] == 0) {
	  state = -1;
	  return;
	}
      }
    }
    state = maxx;
  }
}

void bfs() {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (tmp_y < N && tmp_y >= 0 && tmp_x < M && tmp_x >= 0 && !visit[tmp_y][tmp_x] &&
	  Map[tmp_y][tmp_x] == 0) {
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	Map[tmp_y][tmp_x] = 1;
	date[tmp_y][tmp_x] = date[cur_y][cur_x] + 1;
      }
    }
  }
}

void Out() {
  cout << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << date[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  In();
  bfs();
  //Out();
  check();
  cout << state << endl;

  return 0;
}
