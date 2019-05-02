#include <iostream>
#include <cstdio>

using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int N;
int Map[10][10];

int changed(int d) {
  return (d + 1) % 4;
}

void snail() {
  int cur_x = 0, cur_y = 0;
  int tmp_x, tmp_y;
  int d = 0;
  for (int i = 1; i <= N*N; i++) {
    Map[cur_y][cur_x] = i;
    tmp_y = cur_y + dy[d];
    tmp_x = cur_x + dx[d];
    if (tmp_y >= 0 && tmp_y < N && tmp_x >= 0 && tmp_x < N && Map[tmp_y][tmp_x] == 0) {
      cur_y = tmp_y;
      cur_x = tmp_x;
    }
    else {
      d = changed(d);
      cur_y = cur_y + dy[d];
      cur_x = cur_x + dx[d];
    }
  }
}

void Out() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", Map[i][j]);
    }
    printf("\n");
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      Map[i][j] = 0;
    }
  }
}

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> N;
    init();
    snail();
    Out();
  }
  
  return 0;
}
