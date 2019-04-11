#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int Map[50][50] = {0, };
bool visit[50][50] = {false, };

int N, M;
int dy[] = { -1, 0, 1, 0 };
int dx[] = {0, 1, 0, -1};

vector<pair<int, int> > q;

void Init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      Map[i][j] = 0;
      visit[i][j] = false;
    }
  }
}

int bfs() {
  int cur_y, cur_x;
  int areaNum = 0;
  while (!q.empty()) {
    cur_y = q.back().first;
    cur_x = q.back().second;
    q.pop_back();

    if (!visit[cur_y][cur_x])
      areaNum++;

    int tmp_y, tmp_x;
    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (tmp_y >= 0 && tmp_y < N && tmp_x >= 0 && tmp_x < M && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == 1) {
	q.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
      }
    }
  }
  return areaNum;
}

void In() {
  int num, y, x;
  cin >> N >> M;
  cin >> num;
  for (int i = 0; i < num; i++) {
    scanf("%d", &y);
    scanf("%d", &x);
    q.push_back(make_pair(y, x));
    Map[y][x] = 1;
  }
}

int main() {
  int T;
  cin >> T;
  vector<int> results;
  for (int tc = 0; tc < T; tc++) {
    In();
    results.push_back(bfs());
    Init();
  }

  for (int ans : results) {
    printf("%d\n", ans);
  }

  return 0;
}
