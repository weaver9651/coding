#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int M, N;
int Map[50][500];
int BombMap[50][500];
int up, down, left, right;
vector<pair<int, int> > facts;
vector<pair<int, int> > bombs;
int minn = 1000000;

void In() {
  int tmp;
  scanf("%d%d", &M, &N);
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      BombMap[i][j] = 1;
      scanf("%1d", &tmp);
      Map[i][j] = tmp;
      if (tmp == 1) {
	facts.push_back(make_pair(i, j));
	// up = min(up, i+1);
	// down = max(down, i-1);
	// right = max(right, j-1);
	// left = min(left, j+1);
      }
    }
  }
}

bool isInside(int y , int x) {
  if (y < M && y >= 0 && x < N && x >= 0)
    return true;
  else
    return false;
}

bool isAlive(int y, int x) {
  bool result = true;
  for (int i = y-1; i <= y+1; i++) {
    for (int j = x-1; j <= x+1; j++) {
      if (isInside(i, j) && BombMap[i][j])
	return false;
    }
  }
  return true;
}

void findAnswer(int bomb) {
  int counter = 0;
  for (auto fact : facts) {
    if (isAlive(fact.first, fact.second)) {
      
      counter++;
    }
  }
  minn = min(minn, counter);
}

int main () {
  In();
  findAnswer();
  
  return 0;
}
