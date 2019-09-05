#include <bits/stdc++.h>
using namespace std;

int Map[1001][1001];
int dist[1001][1001] = {0,};
bool visit[1001][1001][2] = {false,};
int N, M;

int dy[] = {0, 0, 1, -1}; // 
int dx[] = {1, -1, 0, 0};

class Person {
public:
  int y, x;
  int crash;
  Person(int y, int x, int crash = 0) : y(y), x(x), crash(crash) {}
};

bool isInside(int y, int x) {
  if (y >= 1 && y <= N && x >= 1 && x <= M) return true;
  else return false;
}

void In() {
  cin >> N >> M;
  int tmp;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      scanf("%1d", &Map[i][j]);
    }
  }
}

int bfs() {
  int cur_y, cur_x, tmp_y, tmp_x;
  int cur_crash, tmp_crash;
  queue<Person> q;
  q.push(Person(1, 1));
  visit[1][1][0] = true;
  dist[1][1] = 1;
  if (N == 1 && M == 1)
    return 1;

  while(!q.empty()) {
    cur_y = q.front().y;
    cur_x = q.front().x;
    cur_crash = q.front().crash;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x)) {
	// normal case
	if (Map[tmp_y][tmp_x] == 0 && !visit[tmp_y][tmp_x][cur_crash]) {
	  visit[tmp_y][tmp_x][cur_crash] = true;
	  dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	  q.push(Person(tmp_y, tmp_x, cur_crash));
	  if (tmp_y == N && tmp_x == M)
	    return dist[tmp_y][tmp_x];
	}
	else if (Map[tmp_y][tmp_x] == 1 && cur_crash == 0 && !visit[tmp_y][tmp_x][1]) {
	  tmp_crash = 1;
	  visit[tmp_y][tmp_x][tmp_crash] = true;
	  dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	  q.push(Person(tmp_y, tmp_x, tmp_crash));
	}
      } // end if isInside
      
    } // end for
    
  } // end while
  return -1;
}

// void Out() {
//   for (int i = 1; i <= N; i++) {
//     for (int j = 1; j <= M; j++) {
//       cout << dist[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;
// }

int main () {
  In();
  int result = bfs();
  cout << result << endl;

  return 0;
}
