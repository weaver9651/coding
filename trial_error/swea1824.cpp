#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

char Map[20][20];
int state[20][20];
int N, M;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int dir;
int mem;
bool isExit;
int cur_y, cur_x;

void In() {
  char tmp;
  scanf("%d%d", &N, &M);
  scanf("%c", &tmp);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%c", &Map[i][j]);
      state[i][j] = -1;
    }
    scanf("%c", &tmp);
  }
  dir = 1;
  mem = 0;
  isExit = false;
  cur_y = 0;
  cur_x = 0;
}

void action(char x) {
  if ('0' <= x && x <= '9') {
    mem = x - 48;
  }
  else {
    switch(x) {
    case '<':
      dir = 3;
      break;
    case '>':
      dir = 1;
      break;
    case '^':
      dir = 0;
      break;
    case 'v':
      dir = 2;
      break;
    case '_':
      if (mem == 0) {
	dir = 1;
      }
      else {
	dir = 3;
      }
      break;
    case '|':
      if (mem == 0) {
	dir = 2;
      }
      else {
	dir = 0;
      }
      break;
    case '.':
      break;
    case '@':
      isExit = true;
      break;
    case '+':
      mem++;
      break;
    case '-':
      mem--;
      break;
    case '?':
      dir = rand() % 4;
      break;
    }
  }
  
  cur_y = (cur_y + dy[dir]) % N;
  cur_x = (cur_x + dx[dir]) % M;
  
  return;
}

void Out() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
}

// bool isEnd() {
//   int a = state[cur_y][cur_x];
//   int b = mem;
//   if (state = )
  
// }

int main () {
  srand(static_cast<unsigned int>(time(0)));

  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    In();
    int counter = 0;
    while (!isExit) {
      action(Map[cur_y][cur_x]);
      counter++;
      if (isExit) {
	printf("#%d YES\n", tc+1);
      }
      // if (counter == 10000) {
      // 	printf("#%d NO\n", tc+1);
      // }

      // if (Map[cur_y][cur_x] == '|' || Map[cur_y][cur_x] == '_') {
	
      // }
      // Map[cur_y][cur_x] = mem;
    }
  }
  
  return 0;
}
