#include <cstdio>
#include <queue>

using namespace std;

int Map[100][100];
bool visit[100][100] = {false, };
int N;
int wmax = 0, wmin = 100;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;  
}

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      visit[i][j] = false;
    }
  }
}

void bfs(int start_y, int start_x, int wlevel) {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] > wlevel) {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
      }
    } // for end
  } // while end
}

int findAns() {
  int maxx = 0;
  for (int k = wmin; k <= wmax; k++) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
	if (!visit[i][j] && Map[i][j] > k) {
	  bfs(i, j, k);
	  cnt++;
	}
      }
    }
    init();
    if (cnt > maxx)
      maxx = cnt;
  } // for k end
  return maxx;
}

void In() {
  scanf("%d", &N);
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp > wmax)
	wmax = tmp;
      if (tmp < wmin)
	wmin = tmp;
    }
  }
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
