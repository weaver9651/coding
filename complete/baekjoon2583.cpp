#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int M, N, K;
int Map[100][100] = {0,};
bool visit[100][100] = {false, };
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

class box {
public:
  int start_x, start_y;
  int end_x, end_y;
  box(int a, int b, int c, int d) : start_x(a), start_y(b), end_x(c), end_y(d) {};
};

vector<box> stk;
vector<int> results;

void In() {
  int a, b, c, d;
  scanf("%d%d%d", &M, &N, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    stk.push_back(box(a, b, c-1, d-1));
  }
}

bool isInbox(int y, int x) {
  for (vector<box>::iterator it = stk.begin(); it != stk.end(); it++) {
    if (y >= it->start_y && y <= it->end_y && x >= it->start_x && x <= it->end_x)
      return true;
  }
  return false;
}

void colorMap() {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (isInbox(i, j))
	Map[i][j] = 1;
      else
	Map[i][j] = 0;
    }
  }
}

void init() {
  while(!stk.empty()) { stk.pop_back(); }
  while(!results.empty()) { results.pop_back(); }

  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      visit[i][j] = false;
}

bool isInside(int y, int x) {
  if (y >= 0 && y < M && x >= 0 && x < N)
    return true;
  else
    return false;
}

void dfs(int y , int x) {
  int cur_y, cur_x, tmp_y, tmp_x;
  vector<pair<int, int> > s;
  s.push_back(make_pair(y, x));
  visit[y][x] = true;
  int counter = 1;
  
  while (!s.empty()) {
    cur_y = s.back().first;
    cur_x = s.back().second;
    s.pop_back();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == 0) {
	s.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	counter++;
      }
    }
  }
  results.push_back(counter);
}

int main () {
  In();
  colorMap();
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++)
      if(!visit[i][j] && !isInbox(i, j))
	dfs(i, j);

  printf("%d\n", results.size());
  sort(results.begin(), results.end());
  for (vector<int>::iterator it = results.begin(); it != results.end(); it++)
    printf("%d ", *it);
  printf("\n");
  
  
  return 0;
}
