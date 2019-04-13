#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

int N, M;
char Map[102][102];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };
bool visit[102][102];
queue<pair<int, int> > p;
vector<pair<int, int> > used;

void In() {
  char tmp;
  cin >> N >> M;
  for (int i = 0; i < M + 2; i++) {
    Map[0][i] = '.';
  }

  scanf("%c", &tmp);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M + 2; j++) {
      if (j == 0 || j == M + 1) {
	Map[i][j] = '.';
      }
      else {
	scanf("%c", &Map[i][j]);
	if (Map[i][j] == '$') {
	  p.push(make_pair(i, j));
	}
      }
    }
    scanf("%c", &tmp);
  }

  for (int i = 0; i < M + 2; i++) {
    Map[N+1][i] = '.';
  }

}

void init() {
  for (int i = 0; i < N + 2; i++) {
    for (int j = 0; j < M + 2; j++) {
      visit[i][j] = false;
    }
  }
}

int **bfs(int y, int x) {
  int **door = new int*[N + 2];
  for (int i = 0; i < N + 2; i++) {
    door[i] = new int[M + 2];
    for (int j = 0; j < M + 2; j++) {
      door[i][j] = 0;
    }
  }
  int counter = 0;
  deque<pair<int, int> > q;
  q.push_back(make_pair(y, x));
  visit[y][x] = true;
  int cur_y, cur_x, tmp_y, tmp_x;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (tmp_y >= 0 && tmp_y < N + 2 && tmp_x >= 0 && tmp_x < M + 2 &&
	  !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != '*') {
	visit[tmp_y][tmp_x] = true;
	if (Map[tmp_y][tmp_x] == '#') {
	  //Map[tmp_y][tmp_x] = '.';
	  door[tmp_y][tmp_x] = door[cur_y][cur_x] + 1;
	  q.push_back(make_pair(tmp_y, tmp_x));
	}
	else {
	  door[tmp_y][tmp_x] = door[cur_y][cur_x];
	  q.push_front(make_pair(tmp_y, tmp_x));
	}
      }
    } // end for
  } // end while
  init();
  return door;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    In();
    int **a = bfs(p.front().first, p.front().second);
    p.pop();

    int **b = bfs(p.front().first, p.front().second);
    p.pop();

    int **c = bfs(0, 0);

    int ans = 10000;
    int cur;
    for (int i = 0; i < N + 2; i++) {
      for (int j = 0; j < M + 2; j++) {
	if (Map[i][j] == '*') continue;
	cur = a[i][j] + b[i][j] + c[i][j];
	if (Map[i][j] == '#') cur -= 2;
	if (ans > cur) {
	  ans = cur;
	}
      }
    }
    cout << ans << endl;
  }
  return 0;
}
