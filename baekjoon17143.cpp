#include <bits/stdc++.h>
using namespace std;

/*
[전체 프로그램 설명]
1. 낚시꾼을 움직임
2. 낚시
3. 물고기를 움직임
  3-1. 물고기를 Map에도 저장해놓고, 물고기가 있는 위치만 따로 vector<pair<int,int> > fish_loc에 저장해놓음(fish_loc만 봐도 바로 물고기가 있는 위치를 알 수 있도록)
  3-2. fish_loc을 보면서 Map에 접근. 이 때 만약에 해당 위치에 물고기 없다면 패스함.
*/

class Fish {
public:
  int y, x, speed, dir, size;
  Fish(int y, int x, int s, int d, int z)
    : y(y), x(x), speed(s), dir(d), size(z) {}
};

int R, C, M;
int cur_fisher;
int point = 0;
vector<Fish> Map[150][150];
vector<Fish> fishes; // 실제 물고기들
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
      if (R != 1)
	s %= (R-1)*2;
    }
    else {
      if (C != 1)
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

// 진짜로 상어를 움직이는 함수
// 상어를 리턴함
Fish realMove(Fish fish) {
  int y = fish.y;
  int x = fish.x;
  int speed = fish.speed;
  int d = fish.dir;

  while (speed) {
    // 0: left, 1: up, 2: down, 3: right
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
  vector<Fish> buffer; // 물고기들을 임시로 저장할 곳
  while (!fishes.empty()) {
    Fish fish = fishes.back(); // 물고기 꺼냄
    fishes.pop_back();

    if (Map[fish.y][fish.x].empty()) continue; // 죽은 물고기

    fish_loc.pop_back(); // 실재하는 물고기라면 fish_loc에서 위치도 pop
    Map[fish.y][fish.x].pop_back(); // Map에서도 일단 제거함

    fish = realMove(fish); // 물고기를 이동시킴
    buffer.push_back(fish); // 이동한 물고기를 임시 buffer에 넣음
  }
  // 그렇게 모든 물고리를 이동시킨 후,
  // 이제 실제로 Map에 반영함
  while (!buffer.empty()) {
    Fish fish = buffer.back(); // buffer에서 물고기 꺼냄
    fishes.push_back(fish);
    buffer.pop_back();
    fish_loc.push_back(make_pair(fish.y, fish.x));

    if (Map[fish.y][fish.x].empty()) { // 다른 물고기가 없다면 그냥 Map에 위치시킴
      Map[fish.y][fish.x].push_back(fish);
    }
    else { // 다른 물고기가 있다면 크기를 비교하여 큰 물고기를 Map에 위치시킴
      Fish fish2 = Map[fish.y][fish.x].back();
      Map[fish.y][fish.x].pop_back();
      if (fish.size > fish2.size) {
	Map[fish.y][fish.x].push_back(fish);
      }
      else {
	Map[fish.y][fish.x].push_back(fish2);
      }
    }
  } // buffer가 빌 때까지 계속 함
}

/* For debugging */
// void Out() {
//   for (int i = 1; i <= R; i++) {
//     for (int j = 1; j <= C; j++) {
//       if (!Map[i][j].empty())
// 	printf("%d ", Map[i][j].back().size);
//       else
// 	printf("0 ");
//     }
//     printf("\n");
//   }
//   printf("\n");
// }

int findAns() {
  cur_fisher = 1;
  while (cur_fisher <= C) {
    getFish();
    moveFish();
    moveFisher();
  }
  return point;
}

int main () {
  In();
  findAns();
  cout << point << endl;

  return 0;
}
