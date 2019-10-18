#include <cstdio>
#include <queue>
using namespace std;

int K, W, H;
int Map[200][200];
bool visit[200][200][30] = {false, };
int dist[200][200] = {0, };
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int djy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int djx[] = {1, 2, 2, 1, -1, -2, -2, -1};

class Monkey {
public:
  int y, x, j;
  Monkey(int y, int x, int j) : y(y), x(x), j(j) {}
};

void In() {
  scanf("%d%d%d", &K, &W, &H);
  int tmp;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < H && x >= 0 && x < W)
    return true;
  else
    return false;
}

int bfs() {
  int cur_y, cur_x, tmp_y, tmp_x;
  int cur_j, tmp_j;
  queue<Monkey> q;
  q.push(Monkey(0, 0, 0));
  visit[0][0][0] = true;

  while (!q.empty()) {
    cur_y = q.front().y;
    cur_x = q.front().x;
    cur_j = q.front().j;
    q.pop();

    // jump
    for (int dj = 0; dj < 8; dj++) {
      tmp_y = cur_y + djy[dj];
      tmp_x = cur_x + djx[dj];
      tmp_j = cur_j + 1;
      if (cur_j < K && isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x][tmp_j] && Map[tmp_y][tmp_x] == 0) {
	q.push(Monkey(tmp_y, tmp_x, tmp_j));
	visit[tmp_y][tmp_x][tmp_j] = true;
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	if (tmp_y == H-1 && tmp_x == W-1)
	  return dist[tmp_y][tmp_x];
      }
    }

    // move
    for (int d = 0; d < 4; d++) {
      tmp_y = cur_y + dy[d];
      tmp_x = cur_x + dx[d];
      tmp_j = cur_j;
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x][cur_j] && Map[tmp_y][tmp_x] == 0) {
	q.push(Monkey(tmp_y, tmp_x, tmp_j));
	visit[tmp_y][tmp_x][tmp_j] = true;
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	if (tmp_y == H-1 && tmp_x == W-1)
	  return dist[tmp_y][tmp_x];
      }
    }
  }
  return -1;
}

int findAns() {
  int result;
  result = bfs();
  return result;
}

int main () {
  In();
  int result;
  result = findAns();
  printf("%d\n", result);
  
  return 0;
}
