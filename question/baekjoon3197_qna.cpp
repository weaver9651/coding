#include <cstdio>
#include <vector>
#include <queue>


using namespace std;

int R, C;
char Map[1500][1500];
int s1_y = -1, s1_x = -1, s2_y = -1, s2_x = -1;
vector<pair<int,int> > remove_cands;
vector<pair<int,int> > swan1_cands;
vector<pair<int,int> > swan2_cands;
vector<pair<int,int> > swan1_buffer;
vector<pair<int,int> > swan2_buffer;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool isInside(int y, int x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

void In() {
  char tmp;
  scanf("%d%d", &R, &C);
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'L') {
	if (s1_y == -1) {
	  s1_y = i;
	  s1_x = j;
	}
	else {
	  s2_y = i;
	  s2_x = j;
	  Map[i][j] = 'R';
	}
      }
    }
    scanf("%c", &tmp); // remove newline
  }
}

void spread(int y, int x, char xxx) {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  vector<bool> visitTmp(C, false);
  vector<vector<bool> > visit(R, visitTmp);
  visit[y][x] = true;
  Map[y][x] = xxx;
  q.push(make_pair(y, x));

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != 'X') {
	Map[tmp_y][tmp_x] = xxx;
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
      }
    }
  }
}

bool spreadSwan(int y, int x, char xxx) {
  bool flag = false;
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  vector<bool> visitTmp(C, false);
  vector<vector<bool> > visit(R, visitTmp);
  visit[y][x] = true;
  q.push(make_pair(y, x));

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] != 'X' &&
	  !visit[tmp_y][tmp_x]) {
	visit[tmp_y][tmp_x] = true;
        if ((xxx == 'L' && Map[tmp_y][tmp_x] == 'R') ||
	    (xxx == 'R' && Map[tmp_y][tmp_x] == 'L')) return true;
	if (Map[tmp_y][tmp_x] != xxx) {
	  q.push(make_pair(tmp_y, tmp_x));
	  Map[tmp_y][tmp_x] = xxx;
	}
      }
      else if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 'X' &&
	       !visit[tmp_y][tmp_x]) {
	visit[tmp_y][tmp_x] = true;
	if (xxx == 'L')
	  swan1_cands.push_back(make_pair(tmp_y, tmp_x));
	else
	  swan2_cands.push_back(make_pair(tmp_y, tmp_x));
      }
    }
  }
  return false;
}

void bfsIce(int y, int x, vector<vector<bool> > &visit) {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  visit[y][x] = true;
  q.push(make_pair(y, x));

  while(!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x]) {
	if (Map[tmp_y][tmp_x] != 'X') {
	  visit[tmp_y][tmp_x] = true;
	  q.push(make_pair(tmp_y, tmp_x));
	}
	else { // Map[tmp_][tmp_x] == 'X'
	  visit[tmp_y][tmp_x] = true;
	  remove_cands.push_back(make_pair(tmp_y, tmp_x));
	}
      }
    }
  }
}

void findIce() {
  vector<bool> visitTmp(C, false);
  vector<vector<bool> > visit(R, visitTmp);
  
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!visit[i][j] && Map[i][j] != 'X')
	bfsIce(i, j, visit);
    }
  }
}

void removeIce() {
  int y, x, tmp_y, tmp_x;
  vector<pair<int,int> > buffer;
  vector<bool> visitTmp(C, false);
  vector<vector<bool> > visit(R, visitTmp);

  while (!remove_cands.empty()) {
    y = remove_cands.back().first;
    x = remove_cands.back().second;
    remove_cands.pop_back();
    visit[y][x] = true;

    Map[y][x] = '.';
    for (int i = 0; i < 4; i++) {
      tmp_y = y + dy[i];
      tmp_x = x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 'X' && !visit[tmp_y][tmp_x]) {
	buffer.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
      }
    }
  }

  while (!buffer.empty()) {
    remove_cands.push_back(buffer.back());
    buffer.pop_back();
  }
}

void Out() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

bool moveSwan() {
  int y, x;
  int tmp_y, tmp_x;
  vector<bool> visitTmp(C, false);
  vector<vector<bool> > visit1(R, visitTmp);

  while (!swan1_cands.empty()) {
    y = swan1_cands.back().first;
    x = swan1_cands.back().second;
    swan1_cands.pop_back();
    visit1[y][x] = true;
    Map[y][x] = 'L';
    
    for (int i = 0; i < 4; i++) { // right, left, up, down
      tmp_y = y + dy[i];
      tmp_x = x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit1[tmp_y][tmp_x]) {
	visit1[tmp_y][tmp_x] = true;
	if (Map[tmp_y][tmp_x] == 'R')
	  return true;
	if (Map[tmp_y][tmp_x] == '.')
	  spread(tmp_y, tmp_x, 'L');
	if (Map[tmp_y][tmp_x] == 'X')
	  swan1_buffer.push_back(make_pair(tmp_y, tmp_x));
      }
    }
  }
  while (!swan1_buffer.empty()) {
    swan1_cands.push_back(swan1_buffer.back());
    swan1_buffer.pop_back();
  }


  vector<vector<bool> > visit2(R, visitTmp);
  
  while (!swan2_cands.empty()) {
    y = swan2_cands.back().first;
    x = swan2_cands.back().second;
    swan2_cands.pop_back();
    visit2[y][x] = true;
    Map[y][x] = 'R';
    
    for (int i = 0; i < 4; i++) {
      tmp_y = y + dy[i];
      tmp_x = x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit2[tmp_y][tmp_x]) {
	visit2[tmp_y][tmp_x] = true;
	if (Map[tmp_y][tmp_x] == 'L')
	  return true;
	if (Map[tmp_y][tmp_x] == '.')
	  spread(tmp_y, tmp_x, 'R');
	if (Map[tmp_y][tmp_x] == 'X')
	  swan2_buffer.push_back(make_pair(tmp_y, tmp_x));
      }
    }
  }
  while(!swan2_buffer.empty()) {
    swan2_cands.push_back(swan2_buffer.back());
    swan2_buffer.pop_back();
  }

  return false;
}

int findAns() {
  int counter = 0;
  bool flag;
  flag = spreadSwan(s1_y, s1_x, 'L');
  spreadSwan(s2_y, s2_x, 'R');
  if (flag) return counter;
  findIce();

  while (true) {
    counter++;
    removeIce();
    if(moveSwan())
      break;
  }

  return counter;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);  
  
  return 0;
}
