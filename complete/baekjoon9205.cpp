#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

typedef pair<int, int> pii;

int N; // the # of cv

void In(vector<pii> &cvs) {
  int x, y;
  for (int i = 0; i < N+2; i++) {
    scanf("%d%d", &x, &y);
    cvs.push_back(make_pair(y, x));
  }
}

bool bfs(vector<pii> &cvs) {
  int cur, tmp;
  int cur_y, cur_x, tmp_y, tmp_x;
  cur = 0;
  vector<bool> visit(N+2, false);
  queue<int> q;
  q.push(cur);
  visit[cur] = true;

  while (!q.empty()) {
    cur = q.front();
    q.pop();
    cur_y = cvs[cur].first;
    cur_x = cvs[cur].second;

    for (int i = 0; i < N+2; i++) {
      tmp_y = cvs[i].first;
      tmp_x = cvs[i].second;
      if (!visit[i] && (abs(tmp_y-cur_y) + abs(tmp_x-cur_x)) <= 1000) {
	visit[i] = true;
	q.push(i);
	if (i == N + 1)
	  return true;
      }
    }
  }
  return false;
}

int main () {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cin >> N;
    vector<pii> cvs;
    In(cvs);
    if(bfs(cvs))
      printf("happy\n");
    else
      printf("sad\n");
  }
}
