#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Map[100][100];
bool visit[100][100];
bool eaten[100][100];
vector<pair<int, int> > eat[101];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0 , 0};

void In() {
  cin >> N;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      eat[tmp].push_back(make_pair(i, j));
    }
  }
}

void initVisit() {
   for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      visit[i][j] = false;
}

void initEaten() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      eaten[i][j] = false;
}

void initEat() {
  for (int i = 1; i <= 100; i++) {
    while (!eat[i].empty())
      eat[i].pop_back();
  }
}

void init() {
  initVisit();
  initEaten();
  initEat();
}

void letsEat(int day) {
  int y, x;
  if (!eat[day].empty()) {
    for (vector<pair<int, int> >::iterator iter = eat[day].begin(); iter != eat[day].end(); iter++) {
      y = iter->first;
      x = iter->second;
      eaten[y][x] = true;
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

void dfs(int y, int x) {
  vector<pair<int ,int> > s;
  s.push_back(make_pair(y, x));
  visit[y][x]= true;
  int cur_y, cur_x, tmp_y, tmp_x;

  while (!s.empty()) {
    cur_y = s.back().first;
    cur_x = s.back().second;
    s.pop_back();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] &&
	  !eaten[tmp_y][tmp_x]) {
	s.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
      }
    }
  }
}

int findAnswer() {
  int maxx = 0;
  for (int day = 1; day <= 100; day++) {
    letsEat(day);
    int counter = 0;
    for (int i = 0; i < N; i++) 
      for (int j = 0; j < N; j++) {
	if (!visit[i][j] && !eaten[i][j]) {
	  dfs(i, j);
	  counter++;
      }
    }
    initVisit();
    maxx = max(maxx, counter);
  }
  if (maxx == 0)
    maxx++;

  return maxx;
}

int main () {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    In();
    printf("#%d %d", tc, findAnswer());
    init();
  }
  
  return 0;
}
