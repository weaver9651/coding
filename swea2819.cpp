#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int Map[4][4];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
char digits[] = {'0', '1', '2', '3', '4', '5',
		 '6', '7', '8', '9'};

vector<string> results;

void In() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &Map[i][j]);
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < 4 && x >= 0 && x < 4)
    return true;
  else
    return false;
}

void findNum(int y, int x, string cur, int index) {
  if (index == 7) {
    results.push_back(cur);
    return;
  }
  
  cur.append(1, digits[Map[y][x]]);
  int tmp_y, tmp_x;
  for (int i = 0; i < 4; i++) {
    tmp_y = y + dy[i];
    tmp_x = x + dx[i];
    if (isInside(tmp_y, tmp_x)) {
      findNum(tmp_y, tmp_x, cur, index + 1);
    }
  }
}

int main () {
  In();
  string cur;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      findNum(i, j, cur, 0);
    }
  }
  sort(results.begin(), results.end());
  results.erase(unique(results.begin(), results.end()), results.end());

  cout << results.size() << endl;
  
  return 0;
}
