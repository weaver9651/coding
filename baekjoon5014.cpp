#include <cstdio>
#include <queue>

using namespace std;

int F, S, G; // F : height, S : start, G : goal
int U, D;

bool visit[1000001] = {false, };
int counter[1000001] = {0, };

void In() {
  scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
}

bool isInside(int x) {
  if (x >= 1 && x <= F)
    return true;
  else
    return false;
}

int bfs() {
  int cur, tmp;
  queue<int> q;
  q.push(S);
  visit[S] = true;
  counter[S] = 1;
  
  if (S == G)
    return 0;

  while(!q.empty()) {
    cur = q.front();
    q.pop();

    tmp = cur + U;
    if (isInside(tmp) && !visit[tmp]) {
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
      if (tmp == G)
	return counter[tmp];
      q.push(tmp);
    }
    
    tmp = cur + D;
    if (isInside(tmp) && !visit[tmp]) {
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
      if (tmp == G)
	return counter[tmp];
      q.push(tmp);
    }

  } // while end
  
  return -1;
}

int main () {
  In();
  int result = bfs();
  if (result != -1)
    printf("%d\n", result);
  else
    printf("use the stairs\n");
  
  return 0;
}
