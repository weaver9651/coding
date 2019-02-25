#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;


/*
NxN map
value means height
height of slope = 1
height of length = L

*/

int N, L;
int map[100][100];
bool isSlope[100][100];

void In() {
  cin >> N >> L;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &map[i][j]);
    }  
  
  return;
}

bool isPass(int i, int j) {
  // too high
  if (abs(map[i][j]-map[i][j-1]) > 1)
    return false;
  
  // down case
  if ((map[i][j-1] - map[i][j]) == 1) {
    for (int k = j; k < j+L; k++) {
      if (isSlope[i][k] || (map[i][k] != map[i][j]) || !(k < N)) {
	return false;
      }
      isSlope[i][k] = true;
    }
  }
  // up case
  if ((map[i][j] - map[i][j-1]) == 1) {
    for (int k = j-1; k >= j-L; k--) {
      if (isSlope[i][k] || (map[i][k] != map[i][j-1]) || !(k >= 0)) {
	return false;
      }
      isSlope[i][k] = true;
    }
  }

  return true;
}
bool isPass2(int i, int j) {
  // too high
  if (abs(map[i][j]-map[i-1][j]) > 1)
    return false;
  
  // down case
  if ((map[i-1][j] - map[i][j]) == 1) {
    for (int k = i; k < i+L; k++) {
      if (isSlope[k][j] || (map[k][j] != map[i][j]) || !(k < N)) {
	return false;
      }
      isSlope[k][j] = true;
    }
  }
  // up case
  if ((map[i][j] - map[i-1][j]) == 1) {
    for (int k = i-1; k >= i-L; k--) {
      if (isSlope[k][j] || (map[k][j] != map[i-1][j]) || !(k >= 0)) {
	return false;
      }
      isSlope[k][j] = true;
    }
  }

  return true;
}


int numSlope() {
  int total = 0;
  // each row
  for (int i = 0; i < N; i++) {
    int count = 0;
    for (int j = 1; j < N; j++) {
      bool test = isPass(i, j);
      if (test) count++;
    }
    if (count == N-1) total++;

  }

  // initialize slope
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      isSlope[i][j] = false;
  
    // each column
    for (int i = 0; i < N; i++) {
      int count = 0;
      for (int j = 1; j < N; j++) {
	bool test = isPass2(j, i);
	if (test) count++;
      }
      if (count == N-1) total++;
    }
  
    return total;
}

int main () {
  
  In();
  cout << numSlope() << endl;
  
  return 0;
}
