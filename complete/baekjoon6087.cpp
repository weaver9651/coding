#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

int W, H;
char Map[101][101];
int dist[101][101];
bool visit[101][101] = {false, };
vector<PII> Cs;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void In() {
  scanf("%d%d", &W, &H);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'c' || tmp == 'C')
	Cs.push_back(make_pair(i, j));
    }
    scanf("%c", &tmp); // remove newline
  }
}

bool isInside(int y ,int x) {
  if (y >= 0 && y < H && x >= 0 && x < W)
    return true;
  else
    return false;
}

void Out() {
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      printf("%d", dist[i][j]);
    }
    printf("\n");
  }
}

void pushDistVisit(int y, int x, queue<PII> &q) {
  int cur_y, cur_x;
  for (int i = 0; i < 4; i++) {
    cur_y = y;
    cur_x = x;
    cur_y += dy[i];
    cur_x += dx[i];
    while (isInside(cur_y, cur_x)) {
      if (Map[cur_y][cur_x] == '*')
	break;
      if (!visit[cur_y][cur_x]) {
	visit[cur_y][cur_x] = true;
	q.push(make_pair(cur_y, cur_x));
	dist[cur_y][cur_x] = dist[y][x] + 1;
      }
      cur_y += dy[i];
      cur_x += dx[i];
    }  // endwhile
  } // endfor
}

int bfs() {
  int cur_y, cur_x, tmp_y, tmp_x;
  int dst_y = Cs.back().first;
  int dst_x = Cs.back().second;
  queue<PII> q;
  cur_y = Cs.front().first;
  cur_x = Cs.front().second;
  dist[cur_y][cur_x] = -1;
  pushDistVisit(cur_y, cur_x, q);
  dist[cur_y][cur_x] = 0;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    pushDistVisit(cur_y, cur_x, q);
    if (visit[dst_y][dst_x])
      return dist[dst_y][dst_x];
  }
  return -1;
}

int findAns() {
  return bfs();
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
}
