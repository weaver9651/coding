#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int Map[500][500];

void In() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", &Map[i][j]);
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M)
    return true;
  else
    return false;
}

int findMaxB1() {
  int maxx = 0;
  int dy[4] = {0, 0, 1, 1};
  int dx[4] = {0, 1, 0, 1};
  int tmp_y, tmp_x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int cur_value = 0;
      for (int k = 0; k < 4; k++) {
	tmp_y = i + dy[k];
	tmp_x = j + dx[k];
	if (isInside(tmp_y, tmp_x)) {
	  cur_value += Map[tmp_y][tmp_x];
	}
	else
	  break;
      }
      maxx = max(maxx, cur_value);
    }
  }
  return maxx;
}

int findMaxB2() {
  int maxx = 0;
  int dy[][4] = {{0, 0, 0, 0},
		 {0, 1, 2, 3}};
  int dx[][4] = {{0, 1, 2, 3},
		 {0, 0, 0, 0}};
  int tmp_y, tmp_x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 2; d++) {
	int cur_value = 0;
	for (int k = 0; k < 4; k++) {
	  tmp_y = i + dy[d][k];
	  tmp_x = j + dx[d][k];
	  if (isInside(tmp_y, tmp_x)) {
	    cur_value += Map[tmp_y][tmp_x];
	  }
	  else
	    break;
	}
	maxx = max(maxx, cur_value);
      }
    }
  }
  return maxx;
}

int findMaxB3() {
  int maxx = 0;
  int dy[][4] = {{0, 1, 1, 2},
		 {0, 0, 1, 1},
		 {0, 1, 1, 2},
		 {0, 0, 1, 1}};
  int dx[][4] = {{0, 0, 1, 1},
		 {1, 2, 0, 1},
		 {1, 0, 1, 0},
		 {0, 1, 1, 2}};
  int tmp_y, tmp_x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 4; d++) {
	int cur_value = 0;
	for (int k = 0; k < 4; k++) {
	  tmp_y = i + dy[d][k];
	  tmp_x = j + dx[d][k];
	  if (isInside(tmp_y, tmp_x)) {
	    cur_value += Map[tmp_y][tmp_x];
	  }
	  else
	    break;
	}
	maxx = max(maxx, cur_value);
      }
    }
  }
  return maxx;
}

int findMaxB4() {
  int maxx = 0;
  int dy[][4] = {{0, 0, 0, 1},
		 {0, 1, 1, 2},
		 {0, 1, 1, 1},
		 {0, 1, 1, 2}};
  int dx[][4] = {{0, 1, 2, 1},
		 {1, 0, 1, 1},
		 {1, 0, 1, 2},
		 {0, 0, 1, 0}};

  int tmp_y, tmp_x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 4; d++) {
	int cur_value = 0;
	for (int k = 0; k < 4; k++) {
	  tmp_y = i + dy[d][k];
	  tmp_x = j + dx[d][k];
	  if (isInside(tmp_y, tmp_x)) {
	    cur_value += Map[tmp_y][tmp_x];
	  }
	  else
	    break;
	}
	maxx = max(maxx, cur_value);
      }
    }
  }
  return maxx;
}

int findMaxB5() {
  int maxx = 0;
  int dy[][4] = {{0, 1, 2, 2},
		 {0, 0, 0, 1},
		 {0, 0, 1, 2},
		 {0, 1, 1, 1},
		 {0, 1, 2, 2},
		 {0, 1, 1, 1},
		 {0, 0, 1, 2},
		 {0, 0, 0, 1}};
  int dx[][4] = {{0, 0, 0, 1},
		 {0, 1, 2, 0},
		 {0, 1, 1, 1},
		 {2, 0, 1, 2},
		 {1, 1, 0, 1},
		 {0, 0, 1, 2},
		 {0, 1, 0, 0},
		 {0, 1, 2, 2}};
  int tmp_y, tmp_x;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 8; d++) {
	int cur_value = 0;
	for (int k = 0; k < 4; k++) {
	  tmp_y = i + dy[d][k];
	  tmp_x = j + dx[d][k];
	  if (isInside(tmp_y, tmp_x)) {
	    cur_value += Map[tmp_y][tmp_x];
	  }
	  else
	    break;
	}
	maxx = max(maxx, cur_value);
      }
    }
  }
  return maxx;
}

int findAns() {
  int maxx = 0;
  maxx = max(maxx, findMaxB1());
  maxx = max(maxx, findMaxB2());
  maxx = max(maxx, findMaxB3());
  maxx = max(maxx, findMaxB4());
  maxx = max(maxx, findMaxB5());
  return maxx;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
