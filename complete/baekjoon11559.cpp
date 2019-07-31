#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define N 12
#define M 6

/*
color : RGBPY
*/

char Map[N][M];
int loc_y = 100;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0}; // left, right, down, up
bool visit[N][M] = {false, };

void In() {
  char tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp != '.')
	loc_y = min(loc_y, i);
    }
    scanf("%c", &tmp); // remove newline
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visit[i][j] = false;
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M)
    return true;
  else
    return false;
}

bool bfs(int start_y, int start_x) {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  vector<pair<int, int> > del;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;
  del.push_back(make_pair(start_y, start_x));
  int counter = 1;

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      char tmp_color = Map[cur_y][cur_x];
      if (isInside(tmp_y, tmp_x) && (Map[tmp_y][tmp_x] == tmp_color) && !visit[tmp_y][tmp_x]) {
	counter++;
	q.push(make_pair(tmp_y, tmp_x));
	del.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
      }
    }
  }
  if (counter >= 4) {
    int del_y, del_x;
    for (vector<pair<int, int> >::iterator it = del.begin(); it != del.end(); it++) {
      del_y = it->first;
      del_x = it->second;
      Map[del_y][del_x] = '.';
    }
    return true;
  }
  else
    return false;
}

bool puyo() {
  bool flag = false;
  for (int i = loc_y; i < N; i++) {
    for (int j = 0; j < M; j++) {

      if (Map[i][j] != '.' && !visit[i][j]) {
	if (bfs(i, j))
	  flag = true;
      }
      
    }
  }
  return flag;
}

int isBlock(int row, int column) {
  for (int i = row; i >= 0; i--) {
    if (Map[i][column] != '.')
      return i;
  }
  return -1;
}

void pullBlock(int block_y, int space_y, int x) {
  char tmp = Map[block_y][x];
  Map[block_y][x] = Map[space_y][x];
  Map[space_y][x] = tmp;
}

void gravity() {
  for (int j = 0; j < M; j++) {
    for (int i = N-1; i > 0; i--) {
      if (Map[i][j] == '.' && isBlock(i, j) != -1) {
	pullBlock(isBlock(i, j), i, j);
      }
    }
  }
}

void Out() {
  for (int i= 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
}

int findAns() {
  int counter = 0;
  while (puyo()) {
    init();
    counter++;
    gravity();
  }
  return counter;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
}
