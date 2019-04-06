#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int Map[4][4];
int dir[4][4] = {0, };
int maxx = 0;

void In() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%1d", &Map[i][j]);
    }
  }
}

int calcRow() {
  int result = 0;
  int now = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (dir[i][j] == 0) {
	now = now * 10 + Map[i][j];
      }
      else {
	result += now;
	now = 0;
	continue;
      }
    }
    result += now;
    now = 0;
  }

  return result;
}

int calcCol() {
  int result = 0;
  int now = 0;
  for (int j = 0; j < M; j++) {
    for (int i = 0; i < N; i++) {
      if (dir[i][j] == 1) {
	now = now * 10 + Map[i][j];
      }
      else {
	result += now;
	now = 0;
	continue;
      }
    }
    result += now;
    now = 0;
  }

  return result;
}


int calc() {
  return calcRow() + calcCol();
}


// bruteforce method
void findMax(int index) {
  if (index == N*M) {
    maxx = max(maxx, calc());
    return;
  }
  findMax(index + 1);
  dir[index / M][index % M] = 1;
  findMax(index + 1);
  dir[index / M][index % M] = 0;
}

int main() {
  In();
  findMax(0);

  cout << maxx << endl;

  return 0;
}
