#include <cstdio>
#include <queue>

using namespace std;

int R, C;
char Map[250][250];
bool visit[250][250] = {false,};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void In() {
  char tmp;
  scanf("%d%d", &R, &C);
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
    }
    scanf("%c", &tmp); // remove newline
  }
}

void Out() { // for debug
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

void bfs(int y, int x, int &cur_wolf, int &cur_sheep) {
  cur_wolf = 0;
  cur_sheep = 0;
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  visit[y][x] = true;
  q.push(make_pair(y, x));
  if (Map[y][x] == 'v')
    cur_wolf++;
  if (Map[y][x] == 'k')
    cur_sheep++;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] &&
	  Map[tmp_y][tmp_x] != '#') {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
	if (Map[tmp_y][tmp_x] == 'v')
	  cur_wolf++;
	if (Map[tmp_y][tmp_x] == 'k')
	  cur_sheep++;
      }
    }
  } // end while
  if (cur_sheep > cur_wolf)
    cur_wolf = 0;
  else
    cur_sheep = 0;
  return;
}

void findAns(int &wolf, int &sheep) {
  wolf = 0;
  sheep = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!visit[i][j] && Map[i][j] != '#') {
	int cur_wolf, cur_sheep;
	bfs(i, j, cur_wolf, cur_sheep);
	wolf += cur_wolf;
	sheep += cur_sheep;
      }
    }
  }
}

int main () {
  In();
  //  Out();
  int wolf, sheep;
  findAns(wolf, sheep);
  printf("%d %d\n", sheep, wolf);
  
  return 0;
}
