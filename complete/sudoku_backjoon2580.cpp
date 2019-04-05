#include <iostream>
#include <vector>

using namespace std;

int Map[9][9];
bool isRow[9][10];
bool isCol[9][10];
bool isSquare[9][10];
bool flag = false;

vector<pair<int, int> > zeros;

void putNumber(int row, int column, int num) {
  isRow[row][num] = true;
  isCol[column][num] = true;
  isSquare[column/3 * 3 + row/3][num] = true;

  return;
}

void removeNumber(int row, int column, int num) {
  isRow[row][num] = false;
  isCol[column][num] = false;
  isSquare[column/3 * 3 + row/3][num] = false;

  return;
}

void In() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> Map[i][j];
      putNumber(i, j, Map[i][j]);
      if (Map[i][j] == 0) {
	zeros.push_back(make_pair(i, j));
      }
    }
  }
}

bool isNumber(int row, int column, int num) {
  if (isRow[row][num] || isCol[column][num] || isSquare[column/3 * 3 + row/3][num])
    return true;
  else
    return false;
}

void completeMap(int index) {
  if (index == zeros.size()) {
    flag = true;
    return;
  }
  for (int i = 1; i <= 9; i++) {
    int cur_y = zeros[index].first;
    int cur_x = zeros[index].second;
    if (!isNumber(cur_y, cur_x, i)) {
      Map[cur_y][cur_x] = i;
      putNumber(cur_y, cur_x, i);
      
      completeMap(index + 1);
      
      if (flag) break;
      
      Map[cur_y][cur_x] = 0;
      removeNumber(cur_y, cur_x, i);
    }
  }
}

int main () {
  In();
  completeMap(0);

  cout << endl;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << Map[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}
