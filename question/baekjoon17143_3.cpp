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
  Shark(int y = -1, int x = -1, int s = -1, int d = -1, int z = -1)
    : y(y), x(x), speed(s), dir(d), size(z) {}
};

Shark Map[101][101]; // 1 ~ R, 1 ~ C
int R, C, M;
int dy[] = { 0, -1, 1, 0 }; // 0: left, 1: up, 2: down, 3: right
int dx[] = { -1, 0, 0, 1 };
int fisher_loc; // 낚시왕 위치
int fisher_point = 0; // 지금까지 잡은 물고기의 무게 총합

queue<Shark> buffer;

void In() {
  int r, c;
  int s, d, z; // speed, direction, size
  scanf("%d%d%d", &R, &C, &M);
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      Map[i][j] = Shark();
    }
  }

  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d%d", &r, &c, &s, &d, &z);
    d %= 4;
    Map[r][c] = Shark(r, c, s, d, z);
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
    if (Map[line][fisher_loc].size != -1) {
      fisher_point += Map[line][fisher_loc].size;
      Map[line][fisher_loc] = Shark();
      return;
    }
    line++;
  }
}

void moveShark(int y, int x) { // real function to move shark
  // mv_counter 횟수만큼 cur_dir방향으로 움직임
  Shark target = Map[y][x];
  Map[y][x] = Shark();
  int mv_counter = target.speed;
  int cur_dir = target.dir;
  int cur_y = y;
  int cur_x = x;
  while (mv_counter) {
    mv_counter--;
    cur_y += dy[cur_dir];
    cur_x += dx[cur_dir];

    // 벽에 도달하면 방향을 바꿈
    if ((cur_dir == 1 || cur_dir == 2) && (cur_y == R || cur_y == 1)) // 1 -> 2, 2 -> 1
      cur_dir ^= 3;
    if ((cur_dir == 0 || cur_dir == 3) && (cur_x == C || cur_x == 1)) // 0 -> 3, 3 -> 0
      cur_dir ^= 3;
  }
  // 움직임을 마친 상어는  buffer에 저장해서 moveShark2 때 실제로 Map에 반영
  buffer.push(Shark(cur_y, cur_x, target.speed, cur_dir, target.size));
}

void moveShark1() { // move but do not update
  // 상어를 움직임
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (Map[i][j].size != -1) { // if shark exists
	moveShark(i, j);
      }
    }
  }
}

void moveShark2() { // update the Map and eat
  // 진짜 Map을 업데이트하고 위치가 겹치는 상어를 처리함
  Shark shark;
  Shark old_shark;
  while (!buffer.empty()) {
    shark = buffer.front();
    buffer.pop();
    if (Map[shark.y][shark.x].size != -1) {
      old_shark = Map[shark.y][shark.x];
      if (old_shark.size >= shark.size) {
	/* do nothing */;
      }
      else { // old_shark.size < shark.size
	Map[shark.y][shark.x] = shark;
      }
    }
    else { // empty
      Map[shark.y][shark.x] = shark;
    }
  }
}

int findAns() {
  while (true) {
    moveFisher(); // 낚시왕 이동
    getFish(); // 가장 먼저 발견하는 물고기 잡음
    moveShark1(); // 상어 이동 시켜서 다른 Map에 저장(바로 진짜 Map에 반영하면 움직였던 상어를 또 움직이는 문제 발생)
    moveShark2(); // 상어를 진짜 Map에 반영시킴
    if (fisher_loc == C)
      return fisher_point;
  }
}

int main() {
  In();
  int result = findAns();
  printf("%d\n", result);
  return 0;
}
