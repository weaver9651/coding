#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
행의 갯수가 많거나 같으면 R연산, 모든 행에 대해서 정렬
행의 갯수가 적으면 C연산, 모든 열에 대해서 정렬

숫자 갯수가 작은 순서대로(pair->second)
그 안에서는 숫자가 작은 순서대로(pair->first)

나머지는 0으로 채우고 정렬한 결과를 낼 때 0은 무시
100개를 넘어가면 그 이후는 버림

최초에는 3x3 행렬
*/

int Map[101][101] = {0, };
int r, c, k;
int cur_r = 3, cur_c = 3;

void In() {
  scanf("%d%d%d", &r, &c, &k);
  for (int i = 1; i <= 3; i++) {
    Map[i][0] = 3;
    Map[0][i] = 3;
    for (int j = 1; j <= 3; j++) {
      scanf("%d", &Map[i][j]);
    }
  }
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
  return (a.second < b.second);
}

bool isInside(int y, int x) {
  if (y >= 1 && x <= cur_r && x >= 1 && x <= cur_c)
    return true;
  else
    return false;
}

int numOfNum(int y, int x, char dir) {
  int tmp = Map[y][x];
  int counter = 0;
  if (dir == 'r') {
    for (int i = 1; i <= 100; i++) {
      if (tmp == Map[y][i]) {
	counter++;
	Map[y][i] = 0;
      }
    }
  }
  else { /* dir == 'c' */
    for (int i = 1; i <= 100; i++) {
      if (tmp == Map[i][x]) {
	counter++;
	Map[i][x] = 0;
      }
    }
  }
  return counter;
}

void calcR() {
  int tmp;
  for (int i = 1; i <= 100; i++) {
    vector<pair<int, int> > s;
    for (int j = 1; j <= 100; j++) {
      if (Map[i][j] != 0) {
	int num = Map[i][j];
	tmp = numOfNum(i, j, 'r');
	s.push_back(make_pair(num, tmp));
      }
    }
    sort(s.begin(), s.end());
    sort(s.begin(), s.end(), sortbysec);
    
    Map[i][0] = s.size() * 2;
    if (Map[i][0] > 100)
      Map[i][0] = 100;
    cur_c = max(cur_c, Map[i][0]);
    
    vector<pair<int,int> >::iterator it = s.begin();
    for (int j = 1; j <= Map[i][0]; /* none */) {
      Map[i][j] = it->first;
      Map[i][j+1] = it->second;
      it++;
      j += 2;
    }
  }
}

void calcC() {
  int tmp;
  for (int j = 1; j <= 100; j++) {
    vector<pair<int, int> > s;
    for (int i = 1; i <= 100; i++) {
      if ((Map[i][j] != 0)) {
	int num = Map[i][j];
	tmp = numOfNum(i, j, 'c');
	s.push_back(make_pair(num, tmp));
	Map[i][j] = 0;
      }
    }
    sort(s.begin(), s.end());
    sort(s.begin(), s.end(), sortbysec);

    Map[0][j] = s.size() * 2;
    if (Map[0][j] > 100)
      Map[0][j] = 100;
    cur_r = max(cur_r, Map[0][j]);
    vector<pair<int, int> >::iterator it = s.begin();
    for (int i = 1; i <= Map[0][j]; /* none */) {
      Map[i][j] = it->first;
      Map[i+1][j] = it->second;
      it++;
      i += 2;
    }
  }
}

void calc() {
  if (cur_r >= cur_c) {
    calcR();
  }
  else {
    calcC();
  }
}

int findAns() {
  int counter = 0;
  while (!(Map[r][c] == k)) {
    calc();
    counter++;
    if (counter > 100)
      return -1;
  }
  if (Map[r][c] == k) {
    return counter;
  }
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
