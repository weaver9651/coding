#include <bits/stdc++.h>
using namespace std;

char Map[101][101];
int N, M;
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}; 
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void In() {
  scanf("%d%d", &N, &M);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      scanf("%c", &tmp);
      Map[i][j] = tmp;
    }
    scanf("%c", &tmp); // remove newline
  }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < M)
    return true;
  else
    return false;
}

void bfs(int y, int x, vector<vector<bool> > &visit) {
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int, int> > q;
  visit[y][x] = true;
  q.push(make_pair(y, x));

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 8; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) &&!visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == '@') {
	visit[tmp_y][tmp_x] = true;
	q.push(make_pair(tmp_y, tmp_x));
      }
    }
  }
}

int findAns() {
  vector<bool> tmpV(M, false);
  vector<vector<bool> > visit(N, tmpV);
  int counter = 0;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!visit[i][j] && Map[i][j] == '@') {
	bfs(i, j, visit);
	counter++;
      }
    }
  }
  return counter;
}

void Out() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%c", Map[i][j]);
    }
    printf("\n");
  }
}

int main () {
  M = 1;
  N = 1;
  while (M != 0) {
    In();
    int result = findAns();
    printf("%d\n", result);
  }
  
  return 0;
}
