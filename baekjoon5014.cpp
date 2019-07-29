#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int F, S, G; // F : height, S : start, G : goal
int U, D;

bool visit[10000001] = {false, };
int counter[10000001] = {0, };

void In() {
  scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
}

void init() {
  bool tmp[10000001] = {false, };
  int tmp2[10000001] = {0, };
  copy(tmp, tmp+10000001, visit);
  copy(tmp2, tmp2+10000001, counter);
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
  
  return 0;
}

int main () {
  In();
  int result = bfs();
  if (result)
    printf("%d\n", result);
  else
    printf("use the stairs\n");
  
  return 0;
}
