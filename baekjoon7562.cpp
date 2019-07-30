#include <cstdio>
#include <queue>

using namespace std;

int Map[300][300];
bool visit[300][300] = {false, };
int src_y, src_x;
int dst_y, dst_x;
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int N;

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Map[i][j] = 0;
      visit[i][j] = false;
    }
  }
}

void In() {
  scanf("%d", &N);
  scanf("%d%d", &src_y, &src_x);
  scanf("%d%d", &dst_y, &dst_x);
}

bool isInside(int y, int x) {
  if( y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

int bfs() {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  q.push(make_pair(src_y, src_x));
  visit[src_y][src_x] = true;
  Map[src_y][src_x] = 0;
  if (src_y == dst_y && src_x == dst_x)
    return 0;

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x]) {
	visit[tmp_y][tmp_x] = true;
	Map[tmp_y][tmp_x] = Map[cur_y][cur_x] + 1;
	q.push(make_pair(tmp_y, tmp_x));
	if (tmp_y == dst_y && tmp_x == dst_x)
	  return Map[dst_y][dst_x];
      }
    }
  }
  return -1;
}

int main () {
  int T;
  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    In();
    init();
    int result = bfs();
    printf("%d\n", result);
  }
  
  return 0;
}
