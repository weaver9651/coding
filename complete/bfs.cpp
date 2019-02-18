#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

bool map[100][100];
int y, x;
int row, column;
int visited[100][100] = {0};
int dir[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};
queue< pair<int, int> > q;

void In() {
  cin >> row >> column;
  int tmp;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++) {
      scanf("%1d", &tmp);
      if (tmp == 1)
	map[i][j] = true;
    }
  
  return;
}

void bfs(){
  int cur_y, cur_x;
  q.push(pair<int, int>(0, 0));
  visited[0][0] = 1;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    int tmp_y, tmp_x;
    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dir[i][0];
      tmp_x = cur_x + dir[i][1];
      if (tmp_y < row && tmp_y >= 0 && tmp_x < column && tmp_x >= 0 && !visited[tmp_y][tmp_x] && map[tmp_y][tmp_x]) {
	q.push(pair<int, int>(tmp_y, tmp_x));
	visited[tmp_y][tmp_x] = visited[cur_y][cur_x] + 1; 
      }
    }
  }

  cout << visited[row-1][column-1] << endl;
  return;
}

int main () {
  In();
  bfs();
  
  return 0;
}
