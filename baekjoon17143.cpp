#include <bits/stdc++.h>
using namespace std;

class Fish {
public:
  int y, x, speed, dir, size;
  Fish(int y, int x, int s, int d, int z)
    : y(y), x(x), speed(s), dir(d), size(z) {}
};

int R, C, M;
int cur_fisher;
int point = 0;
vector<Fish> Map[101][101];
vector<Fish> fishes;
vector<pair<int,int> > fish_loc;
int dy[] = {0, -1, 1, 0}; // 0: left, 1: up, 2: down, 3: right
int dx[] = {-1, 0, 0, 1};

void In() {
  int y, x, s, d, z;
  cin >> R >> C >> M;
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d%d%d", &y, &x, &s, &d, &z);
    d %= 4;
    if (d == 1 || d == 2) {
      s %= (R-1)*2;
    }
    else {
      s %= (C-1)*2;
    }
    Fish fish = Fish(y, x, s, d, z);
    Map[y][x].push_back(fish);
    fishes.push_back(fish);
    fish_loc.push_back(make_pair(y, x));
  }
}

void moveFisher() {
  cur_fisher++;
}

void getFish() {
  for (int r = 1; r <= R; r++) {
    if (!Map[r][cur_fisher].empty()) {
      point += Map[r][cur_fisher].front().size;
      Map[r][cur_fisher].pop_back();
      return;
    }
  }
}

Fish realMove(Fish fish) {
  int y = fish.y;
  int x = fish.x;
  int speed = fish.speed;
  int d = fish.dir;

  while (speed) { // 0: left, 1: up, 2: down, 3: right
    if ((d == 0 && x == 1) || (d == 3 && x == C) || (d == 1 && y == 1) || (d == 2 && y == R))  {
      d ^= 3;
    }
    
    if (d == 0 || d == 3)
      x += dx[d];
    else
      y += dy[d];
    speed--;
  }
  return Fish(y, x, fish.speed, d, fish.size);
}

void moveFish() {
  vector<Fish> buffer;
  while (!fishes.empty()) {
    Fish fish = fishes.back();
    fishes.pop_back();
    if (Map[fish.y][fish.x].empty()) continue;
    fish_loc.pop_back();
    Map[fish.y][fish.x].pop_back();
    fish = realMove(fish);
    buffer.push_back(fish);
  }
  while (!buffer.empty()) {
    Fish fish = buffer.back();
    fishes.push_back(fish);
    buffer.pop_back();
    fish_loc.push_back(make_pair(fish.y, fish.x));

    if (Map[fish.y][fish.x].empty()) {
      Map[fish.y][fish.x].push_back(fish);
    }
    else {
      Fish fish2 = Map[fish.y][fish.x].back();
      Map[fish.y][fish.x].pop_back();
      if (fish.size > fish2.size) {
	Map[fish.y][fish.x].push_back(fish);
      }
      else {
	Map[fish.y][fish.x].push_back(fish2);
      }
    }
  }
}

void Out() {
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (!Map[i][j].empty())
	printf("%d ", Map[i][j].back().size);
      else
	printf("0 ");
    }
    printf("\n");
  }
  printf("\n");
}

int findAns() {
  while (cur_fisher <= C) {
    moveFisher();
    getFish();
    moveFish();
  }
  return point;
}

int main () {
  In();
  findAns();
  cout << point << endl;

  return 0;
}
