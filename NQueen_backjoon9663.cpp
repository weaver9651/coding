#include <iostream>

using namespace std;

bool Map[15][15];
bool isRow[15] = {false, }; 
bool isCol[15] = {false, }; 
bool isNegd[15] = {false, }; 
bool isPosd[15] = {false, };
int counter = 0;

int N;

void In() {
  cin >> N;
}

bool isQueen(int row, int column) {
  if (isRow[row] || isCol[column] || isNegd[row-column + N-1] || isPosd[row + column])
    return true;
  else
    return false;
}

void locateQueen(int row, int column) {
  Map[row][column] = true;
  isRow[row] = true;
  isCol[column] = true;
  isNegd[row - column + N-1] = true;
  isPosd[row + column] = true;

  return;
}

void removeQueen(int row, int column) {
  Map[row][column] = false;
  isRow[row] = false;
  isCol[column] = false;
  isNegd[row - column + N-1] = false;
  isPosd[row + column] = false;

  return;  
}

void dfs(int row) {
  if (row == N) {
    counter++;
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!isQueen(row, i)) {
      locateQueen(row, i);
      dfs(row + 1);
      removeQueen(row, i);
    }
  }
  return;
}


int main () {
  In();
  dfs(0);
  cout << counter << endl;
  
  return 0;
}
