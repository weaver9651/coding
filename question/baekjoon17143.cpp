#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

class Shark {
public:
  int y, x;
  int speed;
  int dir;
  int size;
  Shark(int y = 1, int x = 1, int s = 0, int d = 0, int z = 0) : y(y), x(x), speed(s), dir(d), size(z) {}
};

vector<Shark> Map[101][101]; // 1 ~ R, 1 ~ C
int R, C, M;
int dy[] = {0, -1, 1, 0}; // 0: left, 1: up, 2: down, 3: right
int dx[] = {-1, 0, 0, 1};
int fisher_loc;
int fisher_point = 0;

queue<Shark> buffer;

void In () {
  int r, c;
  int s, d, z; // speed, direction, size 
  scanf("%d%d%d", &R, &C, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
    d %= 4;
    Map[r][c].push_back(Shark(r, c, s, d, z));
  }
  fisher_loc = 0;
  fisher_point = 0;
}

void moveFisher() {
  fisher_loc++;
}

void getFish() {
  int line = 1;
  while (line <= R) {
    if (!Map[line][fisher_loc].empty()) {
      fisher_point += Map[line][fisher_loc].front().size;
      Map[line][fisher_loc].pop_back();
      return;
    }
    line++;
  }
}

void moveShark(int y, int x) { // real function to move shark
  Shark target = Map[y][x].front();
  Map[y][x].pop_back();
  int mv_counter = target.speed;
  int cur_dir = target.dir;
  int cur_y = y;
  int cur_x = x;
  while (mv_counter) {
    mv_counter--;
    cur_y += dy[cur_dir];
    cur_x += dx[cur_dir];
    if ( (cur_dir == 1 || cur_dir == 2 ) && (cur_y == R || cur_y == 1)) // 1 -> 2, 2 -> 1
      cur_dir ^= 3;
    if ((cur_dir == 0 || cur_dir == 3) && (cur_x == C || cur_x == 1)) // 0 -> 3, 3 -> 0
      cur_dir ^= 3;
  }
  buffer.push(Shark(cur_y, cur_x, target.speed, cur_dir, target.size));
}

void moveShark1() { // move but do not update
  for (int i = 1; i <= R; i++) {
    for (int  j = 1; j <= C; j++) {
      if (!Map[i][j].empty()) { // if shark exists
	moveShark(i, j);
      }
    }
  }
}

void moveShark2() { // update the Map and eat
  Shark shark;
  Shark old_shark;
  while (!buffer.empty()) {
    shark = buffer.front();
    buffer.pop();
    if (!Map[shark.y][shark.x].empty()) {
      old_shark = Map[shark.y][shark.x].front();
      if (old_shark.size >= shark.size) {
	/* do nothing */;
      }
      else { // old_shark.size < shark.size
	Map[shark.y][shark.x].pop_back();
	Map[shark.y][shark.x].push_back(shark);
      }
    }
    else { // empty
      Map[shark.y][shark.x].push_back(shark);
    }
  }
}

int findAns() {
  while (true) {
    moveFisher();
    getFish();
    moveShark1();
    moveShark2();
    if (fisher_loc == C)
      return fisher_point;
  }
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  return 0;
}
