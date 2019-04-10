#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
int ry, rx, rd;
int Map[50][50];
bool visit[50][50] = {false, };
// 0: up, 1: right, 2: down, 3: left
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int counter = 0;

void In() {
  cin >> N >> M;
  cin >> ry >> rx >> rd;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%d", &Map[i][j]);
    }
  }
}

bool isClean(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M && visit[y][x] == true)
    return true;
  else
    return false;
}

bool isWall(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M && Map[y][x] == 1)
    return true;
  else
    return false;
}

bool isCleanWall(int y, int x) {
  int counter = 0;
  for (int i = 0; i < 4; i++) {
    if (isWall(y+dy[i], x+dx[i]) || isClean(y+dy[i], x+dx[i]))
      counter++;
  }
  if (counter == 4)
    return true;
  else
    return false;
}

int makeClean() {
  int tmp_y, tmp_x;
  while (true) {
    // clean current cell
    if (visit[ry][rx] == 0) {
      visit[ry][rx] = true;
      counter++;
    }

    if (isCleanWall(ry, rx)) {
      if ( Map[ry + dy[(rd + 2)%4]] [rx + dx[(rd + 2) % 4]] == 1) {
	return counter;
      }
      else {
	ry += dy[(rd + 2) % 4];
	rx += dx[(rd + 2) % 4];
	continue;
      }
    }
    
    // left first if not, change rd, and do again
    while (true) {
      tmp_y = ry + dy[(rd+3) % 4];
      tmp_x = rx + dx[(rd+3) % 4];
      if (visit[tmp_y][tmp_x] == 0 && Map[tmp_y][tmp_x] == 0) {
	ry = tmp_y;
	rx = tmp_x;
	rd = (rd+3) % 4;
	break;
      }
      else {
	rd = (rd+3) % 4;
	continue;
      }
    }
  }
}

int main () {
  In();
  cout << makeClean() << endl;
  
  return 0;
}
