#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Map[20][20];
int N;
int dy[] = {0, 0, 1, -1}; // down, up, right, left
int dx[] = {1, -1, 0, 0};
const int LIMIT = 5;

void In() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> Map[i][j];
    }
  }
}

vector<int> intToDir(int k) {
  vector<int> a(LIMIT);
  for (int i = 0; i < LIMIT; i++) {
    a[i] = (k & 3);
    k >>= 2;
  }
  return a;
}

void move(int d, int** tMap) {
  if (d == 0) { // down
    for (int j = 0; j < N; j++) {

      for (int yellow = 0; yellow < N; yellow++) {
	for (int a = N - 1; a - 1 >= 0; a--) {
	  if (tMap[a][j] == 0) swap(tMap[a][j], tMap[a - 1][j]);
	}
      }

      for (int i = N - 1; i - 1 >= 0; i--) {
	if (tMap[i][j] == 0) swap(tMap[i][j], tMap[i - 1][j]);
	else if (tMap[i][j] == tMap[i - 1][j]) {
	  tMap[i][j] *= 2;
	  tMap[i - 1][j] = 0;
	  for (int k = i - 1; k - 1 >= 0; k--) {
	    swap(tMap[k][j], tMap[k - 1][j]);
	  }
	}
      } // end bubble
    }
  }
  else if (d == 1) { // up
    for (int j = 0; j < N; j++) {

      for (int yellow = 0; yellow < N; yellow++) {
	for (int a = 0; a + 1 < N; a++) {
	  if (tMap[a][j] == 0) swap(tMap[a][j], tMap[a+1][j]);
	}
      }

      for (int i = 0; i +1 < N; i++) {
	int counter = 0;
	if (tMap[i][j] == tMap[i + 1][j]) {
	  tMap[i][j] *= 2;
	  tMap[i + 1][j] = 0;
	  for (int k = i + 1; k + 1 < N; k++) {
	    swap(tMap[k][j], tMap[k + 1][j]);
	  }
	}
      }
    }
  }
  else if (d == 2) { // right
    for (int i = 0; i < N; i++) {

      for (int yellow = 0; yellow < N; yellow++) {
	for (int a = N - 1; a - 1 >= 0; a--) {
	  if (tMap[i][a] == 0) swap(tMap[i][a], tMap[i][a-1]);
	}
      }

      for (int j = N - 1; j - 1 >= 0; j--) {
	if (tMap[i][j] == 0) swap(tMap[i][j], tMap[i][j - 1]);
	else if (tMap[i][j] == tMap[i][j - 1]) {
	  tMap[i][j] *= 2;
	  tMap[i][j - 1] = 0;
	  for (int k = j - 1; k - 1 >= 0; k--) {
	    swap(tMap[i][k], tMap[i][k - 1]);
	  }
	}
      }
    }
  }
  else if (d == 3) { // left
    for (int i = 0; i < N; i++) {

      for (int yellow = 0; yellow < N; yellow++) {
	for (int a = 0; a + 1 < N; a++) {
	  if (tMap[i][a] == 0) swap(tMap[i][a], tMap[i][a+1]);
	}
      }

      for (int j = 0; j + 1< N; j++) {
	if (tMap[i][j] == 0) swap(tMap[i][j], tMap[i][j + 1]);
	else if (tMap[i][j] == tMap[i][j + 1]) {
	  tMap[i][j] *= 2;
	  tMap[i][j + 1] = 0;
	  for (int k = j + 1; k + 1 < N; k++) {
	    swap(tMap[i][k], tMap[i][k + 1]);
	  }
	}
      }
    }
  }
  return;
}

int findMax() {
  int maxx = 0;
  vector<int> dir;
  for (int i = 0; i < (1 << LIMIT*2) - 1; i++) {
    dir = intToDir(i);
    int **tMap = new int*[N];
    for (int n = 0; n < N; n++) {
      tMap[n] = new int[N];
      copy(Map[n], Map[n] + N, tMap[n]);
    }
    for (int j = 0; j < LIMIT; j++) {
      move(dir[j], tMap);
    }
    for (int a = 0; a < N; a++) {
      for (int b = 0; b < N; b++) {
	maxx = max(maxx, tMap[a][b]);
      }
    }
    delete tMap;
  }
  return maxx;
}



int main() {
  In();
  cout << findMax() << endl;

  //int **tMap = new int*[N];
  //for (int n = 0; n < N; n++) {
  //    tMap[n] = new int[N];
  //    copy(Map[n], Map[n] + N, tMap[n]);
  //}

  //move(1, tMap);

  //cout << endl;
  //for (int i = 0; i < N; i++) {
  //    for (int j = 0; j < N; j++) {
  //        cout << tMap[i][j] << " ";
  //    }
  //    cout << endl;
  //}

  return 0;
}
