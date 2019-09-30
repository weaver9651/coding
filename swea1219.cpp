#include <bits/stdc++.h>
using namespace std;

int problem_number;
int N;
int Map[100][2];

void In() {
  scanf("%d", &problem_number);
  scanf("%d", &N);
  for (int i = 0; i < 100; i++) {
    Map[i][0] = -1;
    Map[i][1] = -1;    
  }

  int from, to;
  for (int i = 0; i < N; i++) {
    scanf("%d", &from);
    scanf("%d", &to);
    if (Map[from][0] == -1)
      Map[from][0] = to;
    else
      Map[from][1] = to;
  }
}

bool bfs() {
  vector<bool> visit(100, false);
  int cur, tmp;
  queue<int> q;
  visit[0] = true;
  q.push(0);

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 0; i < 2; i++) {
      if (Map[cur][i] != -1) {
	int tmp = Map[cur][i];
	if (tmp == 99)
	  return true;
        if (!visit[tmp]) {
	  q.push(tmp);
	  visit[tmp] = true;
	}
      }
    }
  }
  return false;
}

int main () {
  for (int i = 0; i < 10; i++) {
    In();
    bool result = bfs();
    printf("#%d %d\n", problem_number, result ? 1 : 0);
  }
  
  return 0;
}
