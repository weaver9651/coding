#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int Map[10000][10000];
bool visit[10000][10000] = {false, };
int target_y, target_x;
int start_y, start_x;
int results[1000];
int T;
int a, b;
int minn = 100000000;
int dir[6][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}};


// 군수열 첫번째 값
int rowInit(int n) {
  int result = (n*n - n + 2) / 2;
  return result;
}

// 첫번째 값의 위치
int findLocation(int num) {
  int counter = 1;
  while(rowInit(counter) <= num) {
    counter++;
  }

  return counter - 2;  
}

void findCell(int num, int &y, int &x) {
  int init = findLocation(num);
  int diff = num - rowInit(init + 1);
  y = init - diff;
  x = diff;
}

int bfs() {
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int ,int> > q;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;
  Map[start_y][start_x] = 0;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    if (cur_y == target_y && cur_x == target_x)
      return Map[cur_y][cur_x];

    for (int i = 0; i < 6; i++) {
      tmp_y = cur_y + dir[i][0];
      tmp_x = cur_x + dir[i][1];
      if (tmp_y >= 0 && tmp_y < 10000 && tmp_x >= 0 && tmp_x < 10000 && !visit[tmp_y][tmp_x]) {
	Map[tmp_y][tmp_x] = Map[cur_y][cur_x] + 1;
	q.push(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
      }
    }
  }
}

void clear() {
  for (int i = 0; i < 10000; i++)
    for (int j = 0; j < 10000; j++)
      visit[i][j] = false;
}

int main () {
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &a);
    scanf("%d", &b);
    findCell(a, start_y, start_x);
    findCell(b, target_y, target_x);
    results[tc] = bfs();
    clear();
  }

  for (int i = 0; i < T; i++)
    cout << "#" << i+1 << " " << results[i] << endl;
  
  return 0;
}
