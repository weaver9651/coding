#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int N, M;
vector<pair<int,int> > results; // node, count
vector<int> edges[100001];

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
  return (a.second > b.second);
}

void In() {
  scanf("%d%d", &N, &M);
  int to, from;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &to, &from);
    if (from == to)
      continue;
    edges[from].push_back(to);
  }
}

int bfs(int start) {
  int cur, tmp;
  queue<int> q;
  bool visit[10001] = {false, };
  int counter = 0;
  q.push(start);
  visit[start] = true;
  counter++;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (vector<int>::iterator it = edges[cur].begin();
	 it != edges[cur].end(); it++) {
      tmp = *it;
      if (!visit[tmp]) {
	visit[tmp] = true;
	counter++;
	q.push(tmp);
      }
    }
  }
  return counter;
}

void findAns() {
  for (int i = 1; i <= N; i++) {
    int result;
    result = bfs(i);
    results.push_back(make_pair(i, result));
  }
}

int main () {
  In();
  findAns();
 
  sort(results.begin(), results.end(), sortbysec);

  vector<int> cands;
  int maxx = results.front().second;
  for (vector<pair<int,int> >::iterator it = results.begin();
       it != results.end(); it++) {
    int node = it->first;
    int count = it->second;
    if (maxx == count) {
      cands.push_back(node);
    }
    else
      break;
  }
  sort(cands.begin(), cands.end(), less<int>());
  for (vector<int>::iterator it = cands.begin();
       it != cands.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
  return 0;
}
