#include <cstdio>
#include <queue>

using namespace std;

bool Map[101][101] = {false, };
int tot[101] = {0, };
int N, M;

void In() {
  scanf("%d%d", &N, &M);

  int a, b;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    Map[a][b] = true;
    Map[b][a] = true;
  }
}

int bfs(int src, int dst) {
  bool visit[101] = {false, };
  visit[src] = true;
  queue<int> q;
  queue<int> buffer;
  buffer.push(src);

  int cur;
  int counter = 0;
  while(!q.empty() || !buffer.empty()) {
    counter++;
    while (!buffer.empty()) {
      q.push(buffer.front());
      buffer.pop();
    }
    while (!q.empty()) {
      cur = q.front();
      q.pop();

      for (int i = 1; i <= N; i++) {
	if (Map[cur][i] && !visit[i]) {
	  if (i == dst)
	    return counter;
	  buffer.push(i);
	  visit[i] = true;
	}
      } // for end
    } // q while end
  } // whiel end
  return 0;
}

int findAns() {
  int minn = 100000000;
  int index;
  int kb;
  for (int i = 1; i <= N; i++) {
    kb = 0;
    for (int j = 1; j <= N; j++) {
      if (i == j)
	continue;
      kb += bfs(i, j);
    }
    if (kb < minn) {
      minn = kb;
      index = i;
    }
  }
  return index;
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
