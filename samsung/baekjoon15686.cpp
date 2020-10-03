/**
 * 오답노트
 * 처음에 거리 구하는 것을 bfs로 했다가 시간 초과가 났음
 * 이 문제는 거리를 구할 때 bfs를 쓸 이유가 전혀 없는 문제
 * */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

vector<pair<int, int>> houses;
vector<pair<int, int>> chickenHouses;
vector<pair<int, int>> liveChickenHouses;
int Map[51][51] = {
    0,
};
int minn = 123456789;
int N, M;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

int chickenDist(int y, int x) {
  int tmpMin = 123456789;
  int tmp;
  for (int i = 0; i < liveChickenHouses.size(); i++) {
    tmp = abs(liveChickenHouses[i].first - y) +
          abs(liveChickenHouses[i].second - x);
    tmpMin = min(tmpMin, tmp);
  }
  return tmpMin;
}

int chickenDistAll() {
  int distSum = 0;
  vector<bool> chickenMapTmp(N, false);
  vector<vector<bool>> chickenMap(N, chickenMapTmp);
  for (int i = 0; i < liveChickenHouses.size(); i++) {
    chickenMap[liveChickenHouses[i].first][liveChickenHouses[i].second] = true;
  }
  for (int i = 0; i < houses.size(); i++) {
    distSum += chickenDist(houses[i].first, houses[i].second);
    if (distSum > minn)
      break;
  }
  return distSum;
}

void combination(int index) {
  if (liveChickenHouses.size() == M) {
    int result = chickenDistAll();
    minn = min(result, minn);
    return;
  }
  if (index >= chickenHouses.size())
    return;

  liveChickenHouses.push_back(chickenHouses[index]);
  combination(index + 1);
  liveChickenHouses.pop_back();
  combination(index + 1);
}

void In() {
  scanf("%d%d", &N, &M);
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp == 1) {
        houses.push_back(make_pair(i, j));
      } else if (tmp == 2) {
        chickenHouses.push_back(make_pair(i, j));
      }
    }
  }
}

int main() {
  In();
  combination(0);
  printf("%d\n", minn);

  return 0;
}