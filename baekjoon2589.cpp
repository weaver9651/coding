#include <cstdio>
#include <queue>

using namespace std;

int N, M;
char Map[50][50];
bool visit[50][50] = {false, };
int dist[50][50] = {0, };
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};


int max(int a, int b) {
  return a > b ? a : b;
}
void In() {
  char tmp;
  scanf("%d%d", &N, &M);
  scanf("%c", &tmp); // remove newline character
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%c", &Map[i][j]);
    }
    scanf("%c", &tmp); // remove newline character
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M)
    return true;
  else
    return false;
}

int bfs(int start_y, int start_x) {
  int maxx = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;
  dist[start_y][start_x] = 0;

  int cur_y, cur_x, tmp_y, tmp_x;
  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == 'L') {
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	maxx = max(maxx, dist[tmp_y][tmp_x]);
      }
    }
  }
  return maxx;
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visit[i][j] = false;
      dist[i][j] = 0;
    }
  }
}

int main () {
  In();
  int maxx = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (Map[i][j] == 'L') {
	maxx = max(maxx, bfs(i, j));
	init();
      }
    }
  }
  printf("%d\n", maxx);  
  
  return 0;
}
