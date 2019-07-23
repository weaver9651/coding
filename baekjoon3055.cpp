#include <cstdio>
#include <queue>

using namespace std;

/*
D : 도착
S : 도치
. : empty
* : water
X : rock
*/

int R, C;
char Map[50][50];
int start_y, start_x;
int dest_y, dest_x;
int water_y = -1, water_x = -1;
bool visit[50][50];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void In() {
  char tmp;
  scanf("%d%d", &R, &C);
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'D') {
	dest_y = i;
	dest_x = j;
      }
      if (tmp == 'S') {
	start_y = i;
	start_x = j;
      }
      if (tmp == '*') {
	water_y = i;
	water_x = j;
      }
    }
    scanf("%c", &tmp); // remove newline
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

int bfs() {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  int wcur_y, wcur_x;
  int wtmp_y, wtmp_x;

  queue<pair<int, int> > q;
  queue<pair<int, int> > buffer;
  queue<pair<int, int> > wq;
  queue<pair<int, int> > wbuffer;
  int time = 0;
  
  buffer.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;

  if (water_y != -1)
    wbuffer.push(make_pair(water_y, water_x));

  while (!q.empty() || !buffer.empty()) {
    time++;
    /* water spread */
    while (!wbuffer.empty()) {
      wq.push(wbuffer.front());
      wbuffer.pop();
    }
    while (!wq.empty()) {
      wcur_y = wq.front().first;
      wcur_x = wq.front().second;
      wq.pop();
      for (int i = 0; i < 4; i++) {
	wtmp_y = wcur_y + dy[i];
	wtmp_x = wcur_x + dx[i];
	if (isInside(wtmp_y, wtmp_x) &&
	    (Map[wtmp_y][wtmp_x] == '.' || Map[wtmp_y][wtmp_x] == 'S')) {
	  Map[wtmp_y][wtmp_x] = '*';
	  wbuffer.push(make_pair(wtmp_y, wtmp_x));
	}
      }
    }
    /* water spread end */

    /* move hedgehog */
    while (!buffer.empty()) {
      q.push(buffer.front());
      buffer.pop();
    }
    while (!q.empty()) {
      cur_y = q.front().first;
      cur_x = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
	tmp_y = cur_y + dy[i];
	tmp_x = cur_x + dx[i];
	if (isInside(tmp_y, tmp_x) && // !visit[tmp_y][tmp_x] &&
	    (Map[tmp_y][tmp_x] == '.' || Map[tmp_y][tmp_x] == 'D')) {
	  buffer.push(make_pair(tmp_y, tmp_x));
	  visit[tmp_y][tmp_x] = true;
	  if (Map[tmp_y][tmp_x] == 'D')
	    return time;
	}
      }
    }
    
  } // bfs start while end
  
  return 0;
} // bfs function end

void init() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      visit[i][j] = false;
    }
  }
}

void Out() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
}

int main () {
  In();
  // Out();
  int result = bfs();
  if (result)
    printf("%d\n", result);
  else
    printf("KAKTUS\n");
  init();
  
  return 0;
}
