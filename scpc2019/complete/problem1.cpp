#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int accumul[1000001] = {0, };
int counter[1000001] = {0, };
bool visit[1000001] = {false, };
int N1, N2;

bool isInside(int num) {
  if (num >= 1 && num <= 1000000)
    return true;
  else
    return false;
}

int bfs() {
  // bfs
  queue<int> q;
  q.push(1);
  visit[1] = true;
  counter[1] = 0;

  int cur, tmp;
  while (!q.empty()) {
    cur = q.front();
    q.pop();

    tmp = cur - 1;
    if (isInside(tmp) && !visit[tmp]) {
      q.push(tmp);
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }

    tmp = cur*2;
    if (isInside(tmp) && !visit[tmp]) {
      q.push(tmp);
      visit[tmp] = true;
      counter[tmp] = counter[cur] + 1;
    }
    
  }
}

long long findAnswer() {
  long long result = 0;
  // // naive version
  // for (int i = N1; i <= N2; i++) {
  //   result += counter[i];
  // }

  // // smart version
  result = accumul[N2] - accumul[N1 - 1];
  return result;
}

void init() {
  for (int i = 0; i < 1000001; i++) {
    visit[i] = false;
  }
}

void calcAccumul() {
  for (int i = 1; i <= 1000000; i++) {
    accumul[i] = accumul[i-1] + counter[i];
  }
}

int main () {
  int T;
  scanf("%d", &T);
  bfs();
  calcAccumul();  
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d%d", &N1, &N2);
    printf("Case #%d\n%lld\n", tc, findAnswer());
  }
  
  return 0;
}
