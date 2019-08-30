#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

/*
0001: left, 0010: up, 0100: right, 1000: down
*/

int N, M;
int Map[50][50];
int maxx = 0;
int counter = 0;
int maxx2 = 0;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

void In() {
  int tmp;
  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
    }
  }
}

bool isOut(int y, int x, int d) {
  if (y == 0 && d == 1)
    return true;
  if (y == M-1 && d == 3)
    return true;
  if (x == 0 && d == 0)
    return true;
  if (x == N-1 && d == 2)
    return true;
  return false;
}

int bfs(int y, int x, bool visit[][50]) {
  int cnt = 0;
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  q.push(make_pair(y, x));
  visit[y][x] = true;
  cnt++;

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (Map[cur_y][cur_x] & (1 << i))
	continue;
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (!visit[tmp_y][tmp_x]) {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
	cnt++;
      }
    }
  }
  return cnt;
}

int bfs2(int y, int x) {
  int cnt = 0;
  int cur_y, cur_x, tmp_y, tmp_x;
  bool visit2[50][50] = {false,};
  queue<pair<int,int> > q;
  q.push(make_pair(y, x));
  visit2[y][x] = true;
  cnt++;

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (Map[cur_y][cur_x] & (1 << i))
	continue;
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (!visit2[tmp_y][tmp_x]) {
	visit2[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
	cnt++;
      }
    }
  }
  return cnt;
}


void findAns() {
  // answer 1, 2
  bool visit[50][50] = {false,};
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (!visit[i][j]) {
	int tmp = bfs(i, j, visit);
	maxx = max(tmp, maxx);
	counter++;
      }
    }
  }

  // answer 3
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      for (int d = 0; d < 4; d++) {
	if (isOut(i, j, d))
	  continue;
	if ( (Map[i][j] & (1 << d)) ) {
	  Map[i][j] ^= (1 << d);
	  int tmp = bfs2(i, j);
	  maxx2 = max(tmp, maxx2);
	  Map[i][j] ^= (1 << d);
	}
      }
    }
  }
}

int main () {
  In();
  findAns();
  printf("%d\n%d\n%d\n", counter, maxx, maxx2);

  return 0;
}
