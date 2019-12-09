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

Shark *Map[101][101] = {NULL, }; // 1 ~ R, 1 ~ C
int R, C, M;
int dy[] = {0, -1, 1, 0}; // 0: left, 1: up, 2: down, 3: right
int dx[] = {-1, 0, 0, 1};
int fisher_loc;
int fisher_point = 0;

queue<Shark*> buffer;

void In () {
  int r, c;
  int s, d, z; // speed, direction, size 
  scanf("%d%d%d", &R, &C, &M);
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      Map[i][j] = NULL;
    }
  }
  
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
    d %= 4; 
    Map[r][c] = new Shark(r, c, s, d, z);
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
    if (Map[line][fisher_loc] != NULL) {
      fisher_point += Map[line][fisher_loc]->size;
      delete Map[line][fisher_loc];
      Map[line][fisher_loc] = NULL;
      return;
    }
    line++;
  }
}

void moveShark(int y, int x) { // real function to move shark
  Shark *target = Map[y][x];
  Map[y][x] = NULL;
  int mv_counter = target->speed;
  int cur_dir = target->dir;
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
  buffer.push(new Shark(cur_y, cur_x, target->speed, cur_dir, target->size));
}

void moveShark1() { // move but do not update
  for (int i = 1; i <= R; i++) {
    for (int  j = 1; j <= C; j++) {
      if (Map[i][j] != NULL) { // if shark exists
	moveShark(i, j);
      }
    }
  }
}

void moveShark2() { // update the Map and eat
  Shark *shark;
  Shark *old_shark;
  while (!buffer.empty()) {
    shark = buffer.front();
    buffer.pop();
    if (Map[shark->y][shark->x] != NULL) {
      old_shark = Map[shark->y][shark->x];
      if (old_shark->size >= shark->size) {
	/* do nothing */;
      }
      else { // old_shark.size < shark.size
	delete Map[shark->y][shark->x];
	Map[shark->y][shark->x] = shark;
      }
    }
    else { // empty
      Map[shark->y][shark->x] = shark;
    }
  }
}

// void Out() {
//   for (int i = 1; i <= R; i++) {
//     for (int j = 1; j <= C; j++) {
//       if (Map[i][j] != NULL)
// 	printf("%d ", Map[i][j]->size);
//       else
// 	printf("0 ");
//     }
//     printf("\n");
//   }
//   printf("\n");
// }

int findAns() {
  while (true) {
    moveFisher();
    // printf("init\n");
    // Out();
    getFish();
    // printf("after getFish\n");
    // Out();
    moveShark1();
    moveShark2();
    // printf("after moveShark\n");
    // Out();
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
