#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Map[25][25];
bool visit[25][25] = {false, };
int num[25][25] = {0, };
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void clearq(queue<pair<int, int> > &q) {
  queue<pair<int, int> > empty;
  swap(q, empty);
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

int bfs(int y, int x) {
  int  counter = 0;
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  q.push(make_pair(y, x));
  visit[y][x] = true;
  counter++;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] &&
	  Map[tmp_y][tmp_x]) {
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	counter++;
      }
    }
  }
  return counter;
}

void In() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &Map[i][j]);
    }
  }
}

void ps() {
  vector<int> results;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visit[i][j] && Map[i][j]) {
	results.push_back(bfs(i, j));
      }
    }
  }
  sort(results.begin(), results.end());
  cout << results.size() << endl;
  for (int i = 0; i < results.size(); i++) {
    cout << results[i] << endl;
  }
}

int main () {
  In();
  ps();  
  
  return 0;
}
