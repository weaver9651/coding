#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int,int> pii;

char Map[21][21];
int dist[21][21];
int W, H;
int abs_y, abs_x;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int dirt;

void In() {
  dirt = 0;
  scanf("%d%d", &W, &H);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'o') {
	abs_y = i;
	abs_x = j;
      }
      if (tmp == '*') {
	dirt++;
      }
    }
    scanf("%c", &tmp); // remove newline
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < H && x >= 0 && x < W)
    return true;
  else
    return false;
}

pii findNearest() {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pii> q;
  vector<bool> vTmp(W, false);
  vector<vector<bool> > visit(H, vTmp);
  cur_y = abs_y;
  cur_x = abs_x;
  q.push(make_pair(cur_y, cur_x));
  visit[cur_y][cur_x] = true;
  dist[cur_y][cur_x] = 0;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int d = 0; d < 4; d++) {
      tmp_y = cur_y + dy[d];
      tmp_x = cur_x + dx[d];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != 'x') {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;

	if (Map[tmp_y][tmp_x] == '*')
	  return make_pair(tmp_y, tmp_x);	
      }
    }
  }
  return make_pair(-1, -1);
}

int findAns() {
  int result = 0;
  int counter = 0;
  while (counter < dirt) {
    pii cell = findNearest(); // bfs
    if (cell.first == -1 && cell.second == -1) {
      return -1;
    }
    else {
      result += dist[cell.first][cell.second];
      counter++;
      Map[cell.first][cell.second] = '.';
      abs_y = cell.first;
      abs_x = cell.second;
    }
  }
  return result;
}

int main () {
  while (true) {
    In();
    if (W == 0 && H == 0)
      break;
    int result = findAns();
    printf("%d\n", result);
  }
  return 0;
}
