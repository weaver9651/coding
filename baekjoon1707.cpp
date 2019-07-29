#include <cstdio>
#include <queue>

using namespace std;

int V, E;
bool visit[20001] = {false, };
bool used[20001][20001] = {false, };
int color[20001] = {0, }; // 0 : none, 1 : black, -1 : red
bool edge[20001][20001] = {false, };

void In() {
  scanf("%d%d", &V, &E);
  int y, x;
  for (int e = 0; e < E; e++) {
    scanf("%d%d", &y, &x);
    edge[y][x] = true;
    edge[x][y] = true;
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

    for (int i = 1; i <= V; i++) {
      if (!used[cur][i] && edge[cur][i]) {
	if (color[i]== 0) {
	  color[i] = color[cur]*(-1);
	  used[cur][i] = true;
	  used[i][cur] = true;	  
	  q.push(i);
	}
	else { // !(color[i] == 0)
	  if (color[i] == color[cur]) {
	    return false;
	  }
	  else { // (color[i] == color[cur])
	    used[cur][i] = true;
	    used[i][cur] = true;
	    q.push(i);
	  }
	}
      } // if (!used[cur][i] && edge[cur][i]) end
    } // for end
  } // while(!q.empty()) end
  return true;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    In();
    printf("%s\n", bfs(1) ? "YES" : "NO");
  }
  
  
  return 0;
}
