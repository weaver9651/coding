#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char Map[1500][1500];
vector<pair<int,int> > swans;
vector<pair<int,int> > remove_cands;
int src_y, src_x, dst_y, dst_x;
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
    for (int j = 0;j < C; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
      if (tmp == 'L') {
	swans.push_back(make_pair(i, j));
	Map[i][j] = '.';
      }
    }
    scanf("%c", &tmp); // remove newline
  }
  src_y = swans[0].first;
  src_x = swans[0].second;
  dst_y = swans[1].first;
  dst_x = swans[1].second;
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

bool bfs() {
  int cur_y, cur_x , tmp_y, tmp_x;
  queue<pair<int,int> > q;
  vector<bool> tmpVisit(C, false);
  vector<vector<bool> > visit(R, tmpVisit);

  q.push(make_pair(src_y, src_x));
  visit[src_y][src_x] = true;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == '.') {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
	if (tmp_y == dst_y && tmp_x == dst_x)
	  return true;
      }
    }
  }
  return false;
}

void removeIce() {
  vector<pair<int,int> > buffer;
  int y, x, tmp_y, tmp_x;
  while (!remove_cands.empty()) {
    y = remove_cands.back().first;
    x = remove_cands.back().second;
    remove_cands.pop_back();
    Map[y][x] = '.';
    for (int i = 0; i < 4; i++) {
      tmp_y = y + dy[i];
      tmp_x = x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 'X')
	buffer.push_back(make_pair(tmp_y, tmp_x));
    }
  }
  while (!buffer.empty()) {
    remove_cands.push_back(buffer.back());
    buffer.pop_back();
  }
}

void findIce(int start_y, int start_x, vector<vector<bool> > &visit) {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x]) {
	if (Map[tmp_y][tmp_x] == '.') {
	  visit[tmp_y][tmp_x] = true;
	  q.push(make_pair(tmp_y, tmp_x));
	}
	else { // Map[tmp_y][tmp_x] == 'X'
	  visit[tmp_y][tmp_x] = true;
	  remove_cands.push_back(make_pair(tmp_y, tmp_x));
	}
      }
    } // end for 
  }
}

void candIce() {
  vector<bool> tmpVisit(C, false);
  vector<vector<bool> > visit(R, tmpVisit);
  
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (!visit[i][j] && Map[i][j] == '.')
	findIce(i, j, visit);
    }
  }
}

int findAns() {
  int counter = 0;
  candIce();

  while (!bfs()) {
    counter++;
    removeIce();
    //    Out();
  }
  
  return counter;
}

int main () {
  In();
  //  Out();
  int result = findAns();
  printf("%d\n", result);

  return 0;
}
