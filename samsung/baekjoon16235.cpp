#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, M, K; // NxN
int foodMap[11][11]; // 1-index
int feedMap[11][11] = {0,};
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<int> treeMap[11][11];
vector<pair<int, pair<int, int> > > deadTree;
vector<pair<int, int> > seedTreeLoc;
// 최초 양분 5
// 봄: 나이만큼 양분 먹고 나이 1증가, 나이 어린 나무 부터, 못먹으면 사망
// 여름: 죽은 나무 양분 나이 / 2 버림
// 가을: 5배수 나이일 때 근처 8칸에 나이 1인 나무 발생
// 겨울: 양분 추가

void In() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      scanf("%d", &feedMap[i][j]);
      foodMap[i][j] = 5;
    }
  }
  int y, x, z;
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &x, &y, &z); // 문제에는 제대로 설명이 안되어 있지만 x가
                                 // 행의 위치, y가 열의 위치이다.
    treeMap[x][y].push_back(z);
  }
}

void spring() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (!treeMap[i][j].empty()) {
        for (int t = 0; t < treeMap[i][j].size(); t++) {
          if (foodMap[i][j] >= treeMap[i][j][t]) {
            foodMap[i][j] -= treeMap[i][j][t];
            treeMap[i][j][t]++;
          } else {
            // erase 못 쓰겠음
            int counter = treeMap[i][j].size() - t;
            while (counter) {
              counter--;
              deadTree.push_back(
                  make_pair(treeMap[i][j].back(), make_pair(i, j)));
              treeMap[i][j].pop_back();
            }
          }
        }
      }
    }
  }
}

void summer() {
  int z, x, y;
  while (!deadTree.empty()) {
    z   = deadTree.back().first;
    x   = deadTree.back().second.first;
    y   = deadTree.back().second.second;
    deadTree.pop_back();
    foodMap[x][y] += (z / 2);
  }
}

bool isInside(int x, int y) {
  if (x >= 1 && x <= N && y >= 1 && y <= N)
    return true;
  else
    return false;
}

void addTree(int x, int y) {
  int tmp_x, tmp_y;
  for (int d = 0; d < 8; d++) {
    tmp_x = x + dx[d];
    tmp_y = y + dy[d];
    if (isInside(tmp_x, tmp_y)) {
      treeMap[tmp_x][tmp_y].push_back(1);
    }
  }
}

void autumn() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int t = 0; t < treeMap[i][j].size(); t++) {
        if (treeMap[i][j][t] % 5 == 0) {
          addTree(i, j);
        }
      }
    }
  }
}

void winter() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      foodMap[i][j] += feedMap[i][j];
      sort(treeMap[i][j].begin(), treeMap[i][j].end());
    }
  }
}

void simulate() {
  while (K) {
    K--;
    spring(); // 양분 먹고 나이 증가
    summer(); // 죽은 나무 양분화
    autumn(); // 번식
    winter(); // 양분추가
  }
}

long countTree() {
  long result = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j<= N; j++) {
      result += treeMap[i][j].size();
    }
  }
  return result;
}

int main() {
  In();
  simulate();
  long numOfTree = countTree();
  printf("%ld\n", numOfTree);

  return 0;
}