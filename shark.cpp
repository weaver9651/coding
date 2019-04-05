#include <iostream>
#include <queue>

using namespace std;

int Map[20][20];
int Time[20][20] = {0, };
bool visit[20][20] = {false, };
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}}; // up, left, right, down
int N;
int sy, sx;
int level = 2;
int expp = 0;
int result;

void In() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Map[i][j];
      if (Map[i][j] == 9) {
	sy = i;
	sx = j;
	Map[i][j] = 0;
      }
    }
  }
}

void init(queue<pair<int, int> > &s) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visit[i][j] = false;
     }
  }
  while(!s.empty()) {
    s.pop();
  }
  return;
}

int bfs() {
  int cur_y = sy;
  int cur_x = sx;
  Time[cur_y][cur_x] = 0;
  queue<pair<int, int> > s;
  s.push(make_pair(cur_y, cur_x));

  while (!s.empty()) {
    cur_y = s.front().first;
    cur_x = s.front().second;
    s.pop();

    if (Map[cur_y][cur_x] > 0 && Map[cur_y][cur_x] < level) {
      Map[cur_y][cur_x] = 0;
      expp++;
      result = Time[cur_y][cur_x];
      cout << "(" << cur_y << ", " << cur_x << ")" << " " << result <<  " level : " << level << endl;
      if (expp == level) {
	expp = 0;
	level++;
	cout << "level up!" << endl;
      }
      init(s);
      visit[cur_y][cur_x] = true;
    }

    int tmp_y, tmp_x;
    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dir[i][0];
      tmp_x = cur_x + dir[i][1];
      if (tmp_y < N && tmp_y >= 0 && tmp_x < N && tmp_x >= 0 && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] <= level) {
	s.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	Time[tmp_y][tmp_x] = Time[cur_y][cur_x] + 1;
      }
    }
  }
}

int main () {
  In();
  bfs();
  cout << result << endl;
  
  return 0;
}
