#include <cstdio>
#include <vector>

using namespace std;

int Map[50][50];
int R, C, T;
vector<pair<int,int> > purifiers;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int p1_y, p1_x, p2_y, p2_x;

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

void In() {
  int tmp;
  scanf("%d%d%d", &R, &C, &T);
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp == -1) {
	purifiers.push_back(make_pair(i, j));
	Map[i][j] = 0;
      }
    }
  }
  vector<pair<int,int> >::iterator it = purifiers.begin();
  p1_y = it->first;
  p1_x = it->second;
  it++;
  p2_y = it->first;
  p2_x = it->second;
}

void spread() {
  int plusMap[50][50] = {0, };
  int tmp_y, tmp_x;
  
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      int cnt = 0;
      if (Map[i][j] > 0) {
	int side = Map[i][j] / 5;
	for (int d = 0; d < 4; d++) {
	  tmp_y = i + dy[d];
	  tmp_x = j + dx[d];
	  if (isInside(tmp_y, tmp_x) &&
	      !((tmp_y == p1_y && tmp_x == p1_x) || (tmp_y == p2_y && tmp_x == p2_x))) {
	    plusMap[tmp_y][tmp_x] += side;
	    cnt++;
	  }
	}
	plusMap[i][j] -= side * cnt;
      }
    }
  }

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      Map[i][j] += plusMap[i][j];
  
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void purify() {
  int cur_y, cur_x;
  // first purifier. counter clockwise
  // down (go into purifier)
  cur_y = p1_y;
  cur_x = p1_x;
  while (cur_y > 0) {
    swap(Map[cur_y][cur_x], Map[cur_y-1][cur_x]);
    cur_y--;
  }
  Map[p1_y][p1_x] = 0;
  
  // left (upper)
  while (cur_x < C-1) {
    swap(Map[cur_y][cur_x], Map[cur_y][cur_x+1]);
    cur_x++;
  }
  Map[p1_y][p1_x] = 0;
  
  // up
  while (cur_y < p1_y) {
    swap(Map[cur_y][cur_x], Map[cur_y+1][cur_x]);
    cur_y++;
  }
  Map[p1_y][p1_x] = 0;
  
  // right
  while (cur_x > 0) {
    swap(Map[cur_y][cur_x], Map[cur_y][cur_x-1]);
    cur_x--;
  }
  Map[p1_y][p1_x] = 0;
  

  // second purifier. clockwise
  cur_y = p2_y;
  cur_x = p2_x;

  // up
  while (cur_y < R-1) {
    swap(Map[cur_y][cur_x], Map[cur_y+1][cur_x]);
    cur_y++;
  }
  Map[p2_y][p2_x] = 0;
  
  // left
  while (cur_x < C-1) {
    swap(Map[cur_y][cur_x], Map[cur_y][cur_x+1]);
    cur_x++;
  }
  Map[p2_y][p2_x] = 0;
  
  // down
  while (cur_y > p2_y) {
    swap(Map[cur_y][cur_x], Map[cur_y-1][cur_x]);
    cur_y--;
  }
  Map[p2_y][p2_x] = 0;
  
  // right
  while (cur_x > 0) {
    swap(Map[cur_y][cur_x], Map[cur_y][cur_x-1]);
    cur_x--;
  }
  Map[p2_y][p2_x] = 0;
  
}

void Out() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%d ", Map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int findAns() {
  for (int t = 0; t < T; t++) {
    /* spread dust */
    spread();
    //Out();

    /* purifier */
    purify();
    //Out();
  }
  
  /* count dust */
  int cnt = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (Map[i][j] > 0)
	cnt += Map[i][j];
    }
  }
  return cnt;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);

  return 0;
}
