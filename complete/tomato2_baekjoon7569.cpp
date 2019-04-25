#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, H;
int Map[100][100][100];
bool visit[100][100][100];
int date[100][100][100];

int dy[] = { 0, 0, 1, -1, 0, 0 };
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int state;

queue<pair<pair<int, int>, int > > q;

void In() {
  cin >> M >> N >> H;
  int tmp;

  state = 0;
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	scanf("%d", &tmp);
	Map[i][j][k] = tmp;
	if (tmp == 0)
	  state = 1;
	if (tmp == 1) {
	  q.push(make_pair(make_pair(i, j), k));
	  visit[i][j][k] = true;
	  date[i][j][k] = 0;
	}
      }
    }
  }
}

bool isInside(int y, int x, int z) {
  if (y < N && y >= 0 && x < M && x >= 0 && z < H && z >= 0)
    return true;
  else
    return false;
}

void bfs() {
  int cur_y, cur_x, cur_z;
  int tmp_y, tmp_x, tmp_z;

  while (!q.empty()) {
    cur_y = q.front().first.first;
    cur_x = q.front().first.second;
    cur_z = q.front().second;
    q.pop();

    for (int i = 0; i < 6; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      tmp_z = cur_z + dz[i];
      if (isInside(tmp_y, tmp_x, tmp_z) && !visit[tmp_y][tmp_x][tmp_z] &&
	  Map[tmp_y][tmp_x][tmp_z] == 0) {
	q.push(make_pair(make_pair(tmp_y, tmp_x), tmp_z));
	visit[tmp_y][tmp_x][tmp_z] = true;
	Map[tmp_y][tmp_x][tmp_z] = 1;
	date[tmp_y][tmp_x][tmp_z] = date[cur_y][cur_x][cur_z] + 1;
      }
    }
  }
}

void check() {
  int maxx = 0;
  for (int k = 0; k < H; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	maxx = max(maxx, date[i][j][k]);
	if (Map[i][j][k] == 0) {
	  state = -1;
	  return;
	}
      }
    }
  }
  state = maxx;
}

int main() {
  In();
  bfs();
  check();
  cout << state << endl;

  return 0;
}
