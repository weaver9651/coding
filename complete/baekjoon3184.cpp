#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int R, C;
char Map[250][250];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
bool visit[250][250] = {false, };
vector<pair<int, int> > wolves;

void In() {
  scanf("%d%d", &R, &C);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'v')
	wolves.push_back(make_pair(i, j));
    }
    scanf("%c", &tmp); // remove newline
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

void bfs(int start_y, int start_x) {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  visit[start_y][start_x] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(start_y, start_x));

  vector<pair<int, int> > locW;
  locW.push_back(make_pair(start_y, start_x));
  vector<pair<int, int> > locS;
  
  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != '#') {
	if (Map[tmp_y][tmp_x] == 'o') {
	  locS.push_back(make_pair(tmp_y, tmp_x));
	}
	if (Map[tmp_y][tmp_x] == 'v') {
	  locW.push_back(make_pair(tmp_y, tmp_x));
	}
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
      }
    }
  }
  if (locW.size() >= locS.size()) {
    for (vector<pair<int, int> >::iterator it = locS.begin();
	 it != locS.end(); it++) {
      tmp_y = it->first;
      tmp_x = it->second;
      Map[tmp_y][tmp_x] = '.';
    }
  }
  else {
    for (vector<pair<int, int> >::iterator it = locW.begin();
	 it != locW.end(); it++) {
      tmp_y = it->first;
      tmp_x = it->second;
      Map[tmp_y][tmp_x] = '.';
    }
  }
}

void findAns(int &wolf, int &sheep) {
  int y, x;
  int cntW = 0;
  int cntS = 0;
  for (vector<pair<int, int> >::iterator it = wolves.begin();
       it != wolves.end(); it++) {
    y = it->first;
    x = it->second;
    bfs(y, x);
  }

  /* find cntW and hcntS */
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (Map[i][j] == 'o')
	cntS++;
      if (Map[i][j] == 'v')
	cntW++;
    }
  }
  wolf = cntW;
  sheep = cntS;
}

int main () {
  In();
  int wolf, sheep;
  findAns(wolf, sheep);
  printf("%d %d\n", sheep, wolf);
  
  return 0;
}
