#include <bits/stdc++.h>
using namespace std;

/*
0 ~ 100000
동규: N
주미: M
+1 -1 +A -A +B -B *A *B
*/

bool visit[100001] = {false,};
int dist[100001] = {0,};
int A, B, src, dst;

void In() {
  cin >> A >> B >> src >> dst;
}

int nextIndex(int index, int num) { // The range of 'num' is 0 to 7.
  int result;
  switch(index) {
  case 0:
    result = num + 1;
    break;
  case 1:
    result = num - 1;
    break;
  case 2:
    result = num + A;
    break;
  case 3:
    result = num - A;
    break;
  case 4:
    result = num + B;
    break;
  case 5:
    result = num - B;
    break;
  case 6:
    result = num*A;
    break;
  case 7:
    result = num*B;
    break;
  }
  return result;
}

bool isInside(int n) {
  if (n >= 0 && n <= 100000) return true;
  else return false;
}

int bfs() {
  if (src == dst)
    return 0;

  int cur, tmp;
  queue<int> q;
  q.push(src);
  visit[src] = true;
  dist[src] = 0;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 0; i < 8; i++) {
      tmp = nextIndex(i, cur);
      if (isInside(tmp) && !visit[tmp]) {
	visit[tmp] = true;
	dist[tmp] = dist[cur] + 1;
	q.push(tmp);
	if (tmp == dst)
	  return dist[tmp];
      }
    }
  }
}

int main () {
  In();
  int result = bfs();
  cout << result << endl;
  
  return 0;
}
