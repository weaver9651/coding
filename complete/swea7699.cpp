#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

char Map[20][20];
int R, C;
int visit[26];
int maxx;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void In() {
  char tmp;
  cin >> R >> C;
  scanf("%c", &tmp);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &Map[i][j]);
    }
    scanf("%c", &tmp);
  }
}

void init() {
  for (int i = 0; i < 26; i++)
    visit[i] = false;
  maxx = 0;
}

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

bool isVisit(char x) {
  int index = x - 'A';
  if (visit[index])
    return true;
  else
    return false;
}

void dfs(int y, int x, int counter) {
  int check = 0;
  int tmp_y, tmp_x;
  for (int i = 0; i < 4; i++) {
    tmp_y = y + dy[i];
    tmp_x = x + dx[i];
    if (isInside(tmp_y, tmp_x) && !isVisit(Map[tmp_y][tmp_x])) {
      visit[Map[tmp_y][tmp_x] - 'A'] = true;
      dfs(tmp_y, tmp_x, counter+1);
      check++;
      visit[Map[tmp_y][tmp_x]- 'A'] = false;
    }
  }
  if (check == 0) {
    maxx = max(counter, maxx);
  }
}

int main() {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    init();
    In();
    visit[Map[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    printf("#%d %d\n", tc+1, maxx);
  }

  return 0;
}
