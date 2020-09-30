#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Shark {
  public:
  int y, x, s, d, z;
  Shark(int y, int x, int s, int d, int z) : y(y), x(x), s(s), d(d), z(z) {}
  Shark() {}
  ~Shark() {}
};

vector<Shark> Map[101][101]; // 1-index
vector<pair<int, int> > sharkLoc;
int R, C, M;
int dy[] = {0, -1, 1, 0, 0}; // 1-index
int dx[] = {0, 0, 0, 1, -1}; // 1-index
vector<Shark> sharkList;

void In() {
  int y, x, s, d, z;
  scanf("%d%d%d", &R, &C, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d%d", &y, &x, &s, &d, &z);
    sharkLoc.push_back(make_pair(y, x));
    Map[y][x].push_back(Shark(y, x, s, d, z));
  }
}

int catchShark(int x) {
  int weight = 0;
  int y = 1; // 1-index
  while (y <= R) {
    if (!Map[y][x].empty()) {
      weight = Map[y][x].back().z;
      Map[y][x].pop_back();
      for (int i = 0; i < sharkLoc.size(); i++) {
        if (sharkLoc[i].first == y && sharkLoc[i].second == x) {
          sharkLoc.erase(sharkLoc.begin() + i);
        }
      }
      return weight;
    }
    y++;
  }
  return 0; // 잡을 상어가 없는 경우
}

bool isInside(int y, int x) {
  if (1 <= y && y <= R && 1 <= x && x <= C) return true;
  else return false;
}

int changeDirection(int d) {
  if (d == 1) return 2;
  else if (d == 2) return 1;
  else if (d == 3) return 4;
  else return 3;
}

void moveShark() {
  int rmod = 2*R - 2;
  int cmod = 2*C - 2;
  for (int i = 0; i < sharkLoc.size(); i++) {
    // sharkLoc 돌아다니면서 Map에서 추출
    int y = sharkLoc[i].first;
    int x = sharkLoc[i].second;
    Shark shark = Map[y][x].front();
    Map[y][x].pop_back();
    int s = shark.s;
    int d = shark.d;
    int z = shark.z;
  
    // 벽을 바라보고 있는지 검사
    if (!isInside(y + dy[d], x + dx[d]))
      d = changeDirection(d);

    // 움직여서 방향, 위치 정하기
    if (d == 1 || d == 2) { // 위, 아래로 움직이는 상어
      s %= rmod;
    } else {
      s %= cmod;
    }
    while (s) {
      s--;
      y += dy[d];
      x += dx[d];
      if (((d == 1 || d == 2) && (y == 1 || y == R)) || ((d == 3 || d == 4) && ( x == 1 || x == C)))
        d = changeDirection(d);
    }
    // sharkList에 배치 후보들 놓기
    sharkList.push_back(Shark(y, x, shark.s, d, z));
  }
  sharkLoc.clear();

  // 배치하면서 큰 상어만 남기기
  while (!sharkList.empty()) {
    Shark shark = sharkList.back();
    sharkList.pop_back();
    if (!Map[shark.y][shark.x].empty()) {
      Shark old = Map[shark.y][shark.x].back();
      if (old.z < shark.z) {
        Map[shark.y][shark.x].pop_back();
        Map[shark.y][shark.x].push_back(shark);
      } else {
        // do nothing
      }
    } else {
      Map[shark.y][shark.x].push_back(shark);
      sharkLoc.push_back(make_pair(shark.y, shark.x));
    }
  }
}

void printMap() {
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (!Map[i][j].empty())
        printf("%d ", Map[i][j].front().z);
      else
        printf("0 ");
    }
    printf("\n");
  }
  printf("\n");
}

int findAns() {
  int man = 1;
  int sum = 0;
  while (man <= C) {
    // 상어 잡기
    sum += catchShark(man);
    // Map에서 상어 빼고, 상어 이동해서 임시 벡터에 저장
    // 임시 벡터에 저장된 상어들을 Map에 배치
    moveShark();

    // printMap();

    // 낚시꾼 이동
    man++;
  }
  return sum;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);

  return 0;
}