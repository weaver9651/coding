#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

/*
spring : 나이만큼 양분 소모, 나이 1 증가
어린나무부터 양분 소모. 못먹으면 죽음.

summer : 죽은 나무의 나이의 절반(버림)만큼 양분

fall : 나이가 5의 배수가 되면 주위 8개 칸에 나이 1인 나무 생성

winter : 땅에 양분 추가

K년 후 살아있는 나무 갯수 
*/

vector<int> Map[11][11];
int provideMap[11][11] = {0,};
int curFoodMap[11][11] = {0,};
int plusMap[11][11] = {0,};
int N;
int M;
int K;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};


bool isInside(int y, int x) {
  if (y >= 1 && y <= N && x >= 1 && x <= N)
    return true;
  else
    return false;
}

void In() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    for (int j = 1 ; j <= N; j++) {
      scanf("%d", &provideMap[i][j]);
      curFoodMap[i][j] = 5;
    }
  }
  int y, x, age;
  for (int m = 0; m < M; m++) {
    scanf("%d%d%d", &y, &x, &age);
    Map[y][x].push_back(age);
  }
}

void spring() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      sort(Map[i][j].begin(), Map[i][j].end());
      int counter = 0;
      for (vector<int>::iterator it = Map[i][j].begin();
	   it != Map[i][j].end(); it++) {
	counter++;
	int &age = *it;
	if (curFoodMap[i][j] >= age) {
	  curFoodMap[i][j] -= age;
	  age++;
	}
	else {
	  while (Map[i][j].size() >= counter) {
	    plusMap[i][j] += Map[i][j].back() / 2;
	    Map[i][j].pop_back();
	  }
	  curFoodMap[i][j] += plusMap[i][j];
	  plusMap[i][j] = 0;
	  break;
	}
      } // for it end
    }
  }
}

void fall() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (vector<int>::iterator it = Map[i][j].begin();
	   it != Map[i][j].end(); it++) {
	int age = *it;
	if (age % 5 == 0) {
	  int tmp_y, tmp_x;
	  for (int d = 0; d < 8; d++) {
	    tmp_y = i + dy[d];
	    tmp_x = j + dx[d];
	    if (isInside(tmp_y, tmp_x)) {
	      Map[tmp_y][tmp_x].push_back(1);
	    }
	  }
	}
      }
    }
  }
}

void winter() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      curFoodMap[i][j] += provideMap[i][j];
    }
  }
}

void farm() {
  for (int i = 0 ; i < K; i++) {
    spring();
    fall();
    winter();
  }
}

int findAns() {
  farm();
  int numOfTree = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      numOfTree += Map[i][j].size();
    }
  }

  return numOfTree;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
