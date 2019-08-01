#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<pair<int, int> > nodes[10001];
int dist[10001] = {0, };
bool visit[10001] = {false, };
int maxx = 0;


void In() {
  scanf("%d", &N);
  int from, to, weight;
  for (int i = 0; i < N-1; i++) {
      scanf("%d%d%d", &from, &to, &weight);
      nodes[from].push_back(make_pair(to, weight));
      nodes[to].push_back(make_pair(from, weight));
  }
}

void init() {
  for (int i = 1; i <= N; i++) {
    visit[i] = false;
    dist[i] = 0;
  }
}

void bfs(int start) {
  int cur, next, weight;
  queue<int> q;
  q.push(start);
  visit[start] = true;
  dist[start] = 0;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (vector<pair<int, int> >::iterator it = nodes[cur].begin();
	 it != nodes[cur].end(); it++) {
      next = it->first;
      weight = it->second;
      if (visit[next])
	continue;
      q.push(next);
      visit[next] = true;
      dist[next] = dist[cur] + weight;
      if (dist[next] > maxx)
	maxx = dist[next];
    }
  }
}

void findAns() {
  for (int i = 1; i <= N; i++) {
    bfs(i);
    init();
  }
}

int main () {
  In();
  findAns();
  printf("%d\n", maxx);
  
  return 0;
}
