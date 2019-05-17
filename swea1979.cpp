#include <iostream>
#include <cstdio>

using namespace std;

int N, K;
int Map[15][15];

void In() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &Map[i][j]);
    }
  }
}

int columncheck() {
  int result = 0;
  for (int j = 0; j < N; j++) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
      if (Map[i][j] == 1) {
	counter++;
      }
      else {
	if (counter == K) {
	  result++;
	}
	counter = 0;
      }
    }
    if (counter == K) {
      result++; 
    }
  }
  
  return result;
}

int rowcheck() {
  int result = 0;
  for (int i = 0; i < N; i++) {
    int counter = 0;
    for (int j = 0; j < N; j++) {
      if (Map[i][j] == 1) {
	counter++;
      }
      else {
	if (counter == K) {
	  result++;
	}
	counter = 0;
      }
    }
    if (counter == K) {
      result++; 
    }
  }
  
  return result;  
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    In();
    int result = 0;
    result += columncheck();
    result += rowcheck();

    printf("#%d %d\n", tc+1, result);
  }
  
  return 0;
}
