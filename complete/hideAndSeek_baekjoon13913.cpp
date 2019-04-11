#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visit[100000] = {false, };
int dist[100000];
int from[100000];

int makeDist(int src, int dst) {
  queue<int> q;
  q.push(src);
  int now, next;

  while (!q.empty()) {
    now = q.front();
    q.pop();
    if (now == dst)
      break;

    next = now + 1;
    if (!visit[next] && next > 0 && next <= 100000) {
      q.push(next);
      visit[next] = true;
      dist[next] = dist[now] + 1;
      from[next] = now;
    }

    next = now * 2;
    if (!visit[next] && next > 0 && next <= 100000) {
      q.push(next);
      visit[next] = true;
      dist[next] = dist[now] + 1;
      from[next] = now;
    }

    next = now - 1;
    if (!visit[next] && next > 0 && next <= 100000) {
      q.push(next);
      visit[next] = true;
      dist[next] = dist[now] + 1;
      from[next] = now;
    }
  }
  return dist[dst];
}

void print(int src, int dst) {
  if (src != dst) {
    print(src, from[dst]);
  }
  cout << dst << " ";
}

int main() {
  cin >> N >> K;

  cout << makeDist(N, K) << endl;
  print(N, K);
  cout << endl;


  return 0;
}
