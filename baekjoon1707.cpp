#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int V, E;
int color[20001] = {0, }; // 0 : none, 1 : black, -1 : red
vector<int> edge[20001];

void In() {
  scanf("%d%d", &V, &E);
  int y, x;
  for (int e = 0; e < E; e++) {
    scanf("%d%d", &y, &x);
    edge[y].push_back(x);
    edge[x].push_back(y);
  }
}

void init() {
  for (int i = 1; i <= V; i++) {
    while(!edge[i].empty())
      edge[i].pop_back();
  }
}

bool bfs(int start) {
  int cur, tmp;
  queue<int> q;
  q.push(start);
  color[start] = 1;

  while(!q.empty()) {
    cur = q.front();
    q.pop();

    for (auto i : edge[cur]) {
      if (color[i] == 0) {
	color[i] = color[cur] * (-1);
	q.push(i);
      }
      else { // i is already colored
	if (color[cur] == color[i])
	  return false;
      }
    }
  } // while(!q.empty()) end
  return true;
}

bool bfsw() {
  for (int i = 1; i <= V; i++) {
    if (color[i] == 0)
      if (!bfs(i))
	return false;
  }
  return true;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    In();
    printf("%s\n", bfsw() ? "YES" : "NO");
    init();
  }
  
  return 0;
}
