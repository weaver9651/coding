#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char Map[1500][1500];
vectnor<pair<short,short> > swans;
queue<pair<short, short> > remove_cands;
short src_y, src_x, dst_y, dst_x;
short dy[] = {0, 0, 1, -1};
short dx[] = {1, -1, 0, 0};

bool isInside(short y, short x) {
  if (y >= 0 && y < R && x >= 0 && x < C)
    return true;
  else
    return false;
}

void In() {
  char tmp;
  scanf("%d%d", &R, &C);
  scanf("%c", &tmp); // remove newline
  for (short i = 0; i < R; i++) {
    for (short j = 0; j < C; j++) {
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
  for (short i = 0; i < R; i++) {
    for (short j = 0; j < C; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

bool bfs() {
  short cur_y, cur_x , tmp_y, tmp_x;
  queue<pair<short,short> > q;
  vector<bool> tmpVisit(C, false);
  vector<vector<bool> > visit(R, tmpVisit);

  q.push(make_pair(src_y, src_x));
  visit[src_y][src_x] = true;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (short i = 0; i < 4; i++) {
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
  short y, x, tmp_y, tmp_x;
  short size = remove_cands.size();
  for (short k = 0; k < size; k++) {
    y = remove_cands.front().first;
    x = remove_cands.front().second;
    remove_cands.pop();
    Map[y][x] = '.';
    for (short i = 0; i < 4; i++) {
      tmp_y = y + dy[i];
      tmp_x = x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 'X')
	remove_cands.push(make_pair(tmp_y, tmp_x));
    }
  }
}

void findIce(short start_y, short start_x, vector<vector<bool> > &visit) {
  short cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<short,short> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (short i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x]) {
	if (Map[tmp_y][tmp_x] == '.') {
	  visit[tmp_y][tmp_x] = true;
	  q.push(make_pair(tmp_y, tmp_x));
	}
	else { // Map[tmp_y][tmp_x] == 'X'
	  visit[tmp_y][tmp_x] = true;
	  remove_cands.push(make_pair(tmp_y, tmp_x));
	}
      }
    } // end for 
  }
}

// void candIce() {
//   vector<bool> tmpVisit(C, false);
//   vector<vector<bool> > visit(R, tmpVisit);
  
//   for (short i = 0; i < R; i++) {
//     for (short j = 0; j < C; j++) {
//       if (!visit[i][j] && Map[i][j] == '.')
// 	findIce(i, j, visit);
//     }
//   }
// }

bool nearWater(int y, int x) {
  bool flag = false;
  int tmp_y, tmp_x;
  for (int i = 0; i < 4; i++) {
    tmp_y = y+dy[i];
    tmp_x = x+dx[i];
    if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == '.')
      flag = true;
  }
  return flag;
}

void candIce() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (Map[i][j] == 'X' && nearWater(i, j)) {
	remove_cands.push(make_pair(i, j));
      }
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
  short result = findAns();
  printf("%d\n", result);

  return 0;
}
