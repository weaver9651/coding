#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int,int>,int> tri;

char Map[101][101];
int dist[101][101];
int W, H;
vector<pair<int,int> > cs;
int dy[] = {-1, 0, 1, 0}; // 0: up, 1: right, 2: down, 3: left
int dx[] = {0, 1, 0, -1};

tri make_tri(int y, int x, int d) {
  return make_pair(make_pair(y, x), d);
}

void In() {
  scanf("%d%d", &W, &H);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      dist[i][j] = 200;
      if (tmp == 'c')
	cs.push_back(make_pair(i, j));
    }
    scanf("%c", &tmp); // remove newline
  }
}

struct cmp {
  bool operator()(const tri &a, const tri &b) {
    return a.second < b.second;
  }
};

bool isInside(int y, int x) {
  if (y >= 0 && y < H && x >= 0 && x < W)
    return true;
  else
    return false;
}

int bfs() {
  int cur_y, cur_x, cur_d, tmp_y, tmp_x, tmp_dist;
  priority_queue<tri, vector<tri>, cmp> q;
  cur_y = cs.front().first;
  cur_x = cs.front().second;
  
  q.push(make_tri(cur_y, cur_x, -1));
  dist[cur_y][cur_x] = 0;

  while (!q.empty()) {
    cur_y = q.top().first.first;
    cur_x = q.top().first.second;
    cur_d = q.top().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (cur_d == -1)
	tmp_dist = 0;
      else
	tmp_dist = (cur_d == i ? 0 : 1);
      if (isInside(tmp_y, tmp_x) &&
	  dist[tmp_y][tmp_x] > dist[cur_y][cur_x] + tmp_dist &&
	  Map[tmp_y][tmp_x] != '*') {
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + tmp_dist;
	q.push(make_tri(tmp_y, tmp_x, i));
	if (tmp_y == cs.back().first && tmp_x == cs.back().second)
	  return dist[tmp_y][tmp_x];
      }
    }
  }
  return -1;
}

int findAns() {
  int result;
  result = bfs();
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
