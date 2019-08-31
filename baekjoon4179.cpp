#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char Map[1000][1000];
vector<pair<int,int> > fire;
int start_y, start_x;
bool visit[1000][1000] = {false,};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

void In() {
  scanf("%d%d", &R, &C);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'F')
	fire.push_back(make_pair(i, j));
      if (tmp == 'J') {
	start_y = i;
	start_x = j;
      }
    }
    scanf("%c", &tmp); // remove newline
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

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

int bfs() {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  queue<pair<int,int> > fq;
  queue<pair<int,int> > buffer;
  queue<pair<int,int> > fbuffer;
  q.push(make_pair(start_y, start_x));

  while(!fire.empty()) {
    fbuffer.push(fire.back());
    fire.pop_back();
  }

  int counter = 0;
  while (!q.empty() || !buffer.empty()) {
    counter++;
    while (!fbuffer.empty()) {
      fq.push(fbuffer.front());
      fbuffer.pop();
    }

    while (!fq.empty()) {
      cur_y = fq.front().first;
      cur_x = fq.front().second;
      fq.pop();

      for (int i = 0; i < 4; i++) {
	tmp_y = cur_y + dy[i];
	tmp_x = cur_x + dx[i];
	if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] != '#' &&
	    Map[tmp_y][tmp_x] != 'F') {
	  Map[tmp_y][tmp_x] = 'F';
	  fbuffer.push(make_pair(tmp_y, tmp_x));
	}
      }
    } // fire spread end

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
	if (isInside(tmp_y, tmp_x)) {
	  if (!visit[tmp_y][tmp_x] &&
	      Map[tmp_y][tmp_x] != '#' && Map[tmp_y][tmp_x] != 'F') {
	    visit[tmp_y][tmp_x] = true;
	    buffer.push(make_pair(tmp_y, tmp_x));
	  }
	}
	else {
	  return counter;
	} 
      }
    }
    
  } // end while
  return -1;
}

int findAns() {
  int result = bfs();
  return result;
}

int main () {
  In();
  //  Out();
   int result = findAns();
  if (result == -1)
    printf("IMPOSSIBLE\n");
  else
    printf("%d\n", result);
  
  return 0;
}
