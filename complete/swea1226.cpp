#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N = 16;
bool Map[N][N] = {0, };
int src_y, src_x;
int dst_y, dst_x;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void In() {
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &tmp);
      if (tmp)
	Map[i][j] = 1;
      else
	Map[i][j] = 0;
      if (tmp == 2) {
	src_y = i;
	src_x = j;
	Map[i][j] = 0;
      }
      else if (tmp == 3) {
	dst_y = i;
	dst_x = j;
	Map[i][j] = 0;
      }
    } // end for j
  } // end for i
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

bool bfs() {
  int cur_y, cur_x, tmp_y, tmp_x;
  vector<bool> vTmp(N, false);
  vector<vector<bool> > visit(N, vTmp);
  queue<pii> q;
  visit[src_y][src_x] = true;
  q.push(make_pair(src_y, src_x));

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 0 && !visit[tmp_y][tmp_x]) {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_x, tmp_y));
	if (tmp_y == dst_y && tmp_x == dst_x)
	  return true;
      }
    }
  }
  return false;
}

int main () {
  int tc;
  for (int i = 1; i <= 10; i++) {
    scanf("%d", &tc);
    In();
    bool result = bfs();
    printf("#%d %d\n", tc, result);
  }
  
  return 0;
}
