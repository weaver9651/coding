#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int edge[100][100];
bool visit[100];
int Map[100][100];

void In() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &edge[i][j]);
    }
  }
}

void init() {
  for (int i = 0; i < N; i++) {
    visit[i] = false;
  }
}

bool bfs(int src, int dst) {
  queue<int> q;
  q.push(src);
  int cur;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 0; i < N; i++) {
      if (i == cur)
	continue;
      if (edge[cur][i] && !visit[i]) {
	if (i == dst) {
	  init();
	  return true;
	}
	q.push(i);
	visit[i] = true;
      }
    }
  }
  init();
  return false;
}

void Out() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (bfs(i, j))
	printf("%d ", 1);
      else
	printf("%d ", 0);
    }
    cout << endl;
  }
}

int main () {
  In();
  Out();
  
  return 0;
}
