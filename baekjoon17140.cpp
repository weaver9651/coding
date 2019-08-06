#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
int Map[101][101] = {0, };
int max_column = 0, max_row = 0;

void In() {
  scanf("%d%d%d", &R, &C, &K);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &Map[i][j]);
      if (Map[i][j] != 0) {
	max_column = max(max_column, i);
	max_row = max(max_row, j);
      }
    }
  }
  
}

void Out() {
  for (int i = 1; i <= max_row; i++) {
    for (int j = 1; j <= max_column; j++) {
      printf("%d ", Map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int numOfNum(int y, int x, char dir) {
  int counter = 0;
  int num = Map[y][x];
  if (dir == 'r') { // change column
    for (int i = x; i <= max_column; i++) {
      if (Map[y][i] == num) {
	counter++;
	Map[y][i] = 0;
      }
    }
  }
  else { /* dir == 'c' */ // change row
    for (int i = y; i <= max_row; i++) {
      if (Map[i][x] == num) {
	counter++;
	Map[i][x] = 0;
      }
    }
  }
  return counter;
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
  return (a.second < b.second);
}

void calR() {
  int num, cnt, cur_size;
  int tmp_column = 0;
  for (int i = 1; i <= max_row; i++) {
    vector<pair<int,int> > s;
    for (int j = 1; j <= max_column; j++) {
      if (Map[i][j] != 0) {
	num = Map[i][j];
	cnt = numOfNum(i, j, 'r');
	s.push_back(make_pair(num, cnt));
      }
    }
    /* locate numbers from s */
    cur_size = s.size() * 2;
    if (cur_size > 100)
      cur_size = 100;
    tmp_column = max(tmp_column, cur_size);

    sort(s.begin(), s.end());
    sort(s.begin(), s.end(), sortbysec);

    vector<pair<int,int> >::iterator it = s.begin();
    for (int j = 1; j <= cur_size; /* none */) {
      Map[i][j] = it->first;
      Map[i][j+1] = it->second;
      j += 2;
      it++;
    }        
  }
  max_column = tmp_column;
}

void calC() {
  int num, cnt, cur_size;
  int tmp_row = 0;
  for (int j = 1; j <= max_column; j++) {
    vector<pair<int,int> > s;
    for (int i = 1; i <= max_row; i++) {
      if (Map[i][j] != 0) {
	num = Map[i][j];
	cnt = numOfNum(i, j, 'c');
	s.push_back(make_pair(num, cnt));
      }
    }
    /* locate numbers from s */
    cur_size = s.size() * 2;
    if (cur_size > 100)
      cur_size = 100;
    tmp_row = max(tmp_row, cur_size);

    sort(s.begin(), s.end());
    sort(s.begin(), s.end(), sortbysec);

    vector<pair<int,int> >::iterator it = s.begin();
    for (int i = 1; i <= cur_size; /* none */) {
      Map[i][j] = it->first;
      Map[i+1][j] = it->second;
      i += 2;
      it++;
    }        
  }
  max_row = tmp_row;
}

void cal() {
  if (max_row >= max_column) {
    calR();
  }
  else {
    calC();
  }
}

int findAns() {
  int counter = 0;
  while(Map[R][C] != K) {
    counter++;
    if (counter > 100)
      return -1;
    cal();
  }
  return counter;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
