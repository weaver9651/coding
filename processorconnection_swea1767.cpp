#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Map[12][12];
vector <pair<int, int> > coreQ;
int minn;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void In() {
  cin >> N;
  minn = N*N;
  while (!coreQ.empty()) {
    coreQ.pop_back();
  }
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0 ; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp == 1) {
	coreQ.push_back(make_pair(i, j));
      }
    }
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

bool makeRoad(int **arr, int y, int x, int d) {
  int cur_y = y + dy[d];
  int cur_x = x + dx[d];
  while (isInside(cur_y, cur_x)) {
    if (arr[cur_y][cur_x])
      return false;
    
    arr[cur_y][cur_x] = 2;
    cur_y += dy[d];
    cur_x += dx[d];
  }
  return true;
}

int calc(int **arr) {
  int counter = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == 2)
	counter++;
    }
  }
  return counter;
}

// for debugging
void Out(int **arr) {
  cout << endl;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void solve(int **arr, int index) {
  if (index == coreQ.size()) {
    minn = min(minn, calc(arr));
    for (int i = 0; i < N; i++) {
      delete arr[i];
    }
    delete[] arr;
    return;
  }
  for (int d = 0; d < 4; d++) {
    // copy array to ***newarr
    int **newarr = new int*[N];
    for (int i = 0; i < N; i++) {
      newarr[i] = new int[N];
      copy(arr[i], arr[i]+N, newarr[i]);
    }
    // copy array end
    if (makeRoad(newarr, coreQ[index].first, coreQ[index].second, d)) {
      solve(newarr, index+1);
    }
    else {
      for (int i = 0; i < N; i++) {
	delete newarr[i];
      }
      delete[] newarr;
    }
  }
}

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    In();
    int **newarr = new int*[N];
    for (int i = 0; i < N; i++) {
      newarr[i] = new int[N];
      copy(Map[i], Map[i]+N, newarr[i]);
    }
    solve(newarr, 0);
    printf("#%d %d\n", tc+1, minn);
    for (int i = 0; i < N; i++) {
      delete newarr[i];
    }
    delete[] newarr;
  }
  
  return 0;
}
