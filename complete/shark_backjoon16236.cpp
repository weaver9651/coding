#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int Map[20][20];
int Time[20][20] = { 0, };
bool visit[20][20] = { false, };
int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} }; // up, left, right, down
int N;
int sy, sx;
int level = 2;
int expp = 0;
int result = 0;

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
  while (!s.empty()) {
    s.pop();
  }
  return;
}

void bfs() {
  int cur_y = sy;
  int cur_x = sx;
  Time[cur_y][cur_x] = 0;
  queue<pair<int, int> > s;
  vector<pair<int, int> > eat;
  s.push(make_pair(cur_y, cur_x));
  while (true) {
    while (!s.empty()) {
      cur_y = s.front().first;
      cur_x = s.front().second;
      s.pop();

      if (Map[cur_y][cur_x] > 0 && Map[cur_y][cur_x] < level) {
	eat.push_back(make_pair(cur_y, cur_x));
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
    // 모두 탐색 후
    if (eat.empty())
      break;
    int dist = Time[eat.front().first][eat.front().second];
    int eat_y = eat.front().first;
    int eat_x = eat.front().second;
    int tmp_y, tmp_x;
    for (vector<pair<int, int> >::const_iterator iter = eat.begin(); iter != eat.end(); iter++) {
      tmp_y = iter->first;
      tmp_x = iter->second;
      if (dist == Time[tmp_y][tmp_x]) {
	if (tmp_y < eat_y) {
	  eat_y = tmp_y;
	  eat_x = tmp_x;
	}
	else if (tmp_y == eat_y && tmp_x < eat_x) {
	  eat_y = tmp_y;
	  eat_x = tmp_x;
	}
      }
    }
    while (!eat.empty()) {
      eat.pop_back();
    }
    cur_y = eat_y;
    cur_x = eat_x;
    Map[cur_y][cur_x] = 0;
    expp++;
    result += Time[cur_y][cur_x];
    if (expp == level) {
      expp = 0;
      level++;
    }
    visit[cur_y][cur_x] = true;
    Time[cur_y][cur_x] = 0;
    init(s);
    s.push(make_pair(cur_y, cur_x));
  }
}

int main() {
  In();
  bfs();
  cout << result << endl;

  return 0;
}
