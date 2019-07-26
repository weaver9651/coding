#include <cstdio>
#include <queue>

using namespace std;

int N;
int src, dst;
bool Map[101][101] = {false, };
bool visit[101] = {false, };
int count[101] = {0, };

void In() {
  scanf("%d%d%d", &N, &src, &dst);
  int tmp, y, x;
  scanf("%d", &tmp);
  for (int i = 0; i < tmp; i++) {
    scanf("%d%d", &y, &x);
    Map[y][x] = true;
    Map[x][y] = true;
  }
}

int bfs() {
  queue<int> q;
  q.push(src);
  visit[src] = true;
  int cur, tmp;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 1; i <= N; i++) {
      if (i == cur) continue;
      if (!visit[i] && Map[cur][i]) {
	q.push(i);
	count[i] = count[cur] + 1;
	visit[i] = true;
	if (i == dst) return count[dst];
      }
    }
  }
  return -1;
}

int main() {
  In();
  int result = bfs();
  printf("%d\n", result);
  
  return 0;
}
