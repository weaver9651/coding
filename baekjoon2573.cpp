#include <cstdio>
#include <queue>

using namespace std;

int N, M;
int Map[300][300] = {0,};
int visit[300][300] = {false, };
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void In() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &Map[i][j]);
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M)
    return true;
  else
    return false;
}

int numOfSea(int y, int x) {
  int counter = 0;
  int tmp_y, tmp_x;
  for (int i = 0; i < 4; i++) {
    tmp_y = y + dy[i];
    tmp_x = x + dx[i];
    if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 0) {
      counter++;
    }
  }
  return counter;
}

void meltdown() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (Map[i][j]) {
	Map[i][j] -= numOfSea(i, j);
	if (Map[i][j] < 0)
	  Map[i][j] = 0;
      }
    }
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visit[i][j] = false;
    }
  }
}

void bfs(int start_y, int start_x) {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] && !visit[tmp_y][tmp_x]) {
        visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
      }
    }
  }
}

int numOfIce() {
  int counter = 0;
  init();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (Map[i][j] && !visit[i][j]) {
	bfs(i, j);
	counter++;
      }
    }
  }
  return counter;
}

int findAns() {
  int year = 0;
  int num;
  while (true) {
    meltdown();
    num = numOfIce();
    year++;
    if (num >= 2)
      return year;
    if (num == 0)
      return 0;
  }
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
