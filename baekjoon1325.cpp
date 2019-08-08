#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

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
    edges[from].push_back(to);
  }
}

int bfs(int start) {
  int cur, tmp;
  queue<int> q;
  bool visit[10001] = {false,};
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
    int maxx;
    maxx = bfs(i);
    results.push_back(make_pair(i, maxx));
  }
}

int main () {
  In();
  findAns();
  sort(results.begin(), results.end());
  sort(results.begin(), results.end(), sortbysec);
  int maxx = results.front().second;
  for (vector<pair<int,int> >::iterator it = results.begin();
       it != results.end(); it++) {
    int node = it->first;
    int count = it->second;
    if (maxx == count) {
      printf("%d ", node);
    }
    else
      break;
  }
  printf("\n");
  
  return 0;
}
