#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int Map[50][50]; // 0 : empty, 1 : wall, 2 : virus
int N, M;
vector<pair<int,int> > viruses;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int cnt_wall;

bool isInside(int y, int x) {
  if (x >= 0 && x < N && y >= 0 && y < N)
    return true;
  else
    return false;
}

void In() {
  scanf("%d%d", &N, &M);
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp == 2) {
	viruses.push_back(make_pair(i, j));
      }
      if (tmp == 1)
	cnt_wall++;
    }
  }
}

bool isFull(bool visit[50][50]) {
  int count = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (Map[i][j] == 0 && !visit[i][j])
	return false;
  return true;
}

int bfs(vector<pair<int,int> > s) {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  bool visit[50][50] = {false,};
  int dist[50][50] = {0,};
  queue<pair<int,int> > q;
  
  for (vector<pair<int,int> >::iterator it = s.begin();
       it != s.end(); it++) {
    tmp_y = it->first;
    tmp_x = it->second;
    visit[tmp_y][tmp_x] = true;
    q.push(*it);
  }

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != 1) {
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
      }
    }
  }

  if (isFull(visit)) {
    int maxx = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
	if (Map[i][j] != 2)
	  maxx = max(maxx, dist[i][j]);
    return maxx;
  }
  else
    return -1;
}

int findAns() {
  int minn = 10000;
  // combination
  vector<int> comb;
  for (int i = 0; i < viruses.size() - M; i++) {
    comb.push_back(0);
  }
  for (int i = 0; i < M; i++) {
    comb.push_back(1);
  }
  
  do {
    vector<pair<int,int> > s;
    for (int i = 0; i < viruses.size(); i++) {
      if (comb[i] == 1)
	s.push_back(make_pair(viruses[i].first, viruses[i].second));
    }
    int cur_result = bfs(s);
    if (cur_result != -1)
      minn = min(minn, cur_result);
  } while (next_permutation(comb.begin(), comb.end()));
  
  if (minn == 10000)
    return -1;
  else
    return minn;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
