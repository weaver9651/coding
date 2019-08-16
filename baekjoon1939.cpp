#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long MAX_WEIGHT = 1000000000;
int N, E;
vector<pair<int,long long> > edges[100001];
int src, dst;

void In() {
  scanf("%d%d", &N, &E);
  int from, to;
  long long weight;
  for (int i = 0; i < E; i++) {
    scanf("%d%d%lld", &from, &to, &weight);
    edges[from].push_back(make_pair(to, weight));
    edges[to].push_back(make_pair(from, weight));
  }
  scanf("%d%d", &src, &dst);
}

class truck {
public:
  int cur;
  long long weight;
  truck(int cur, long long weight) : cur(cur), weight(weight) {}
};

long long bfs() {
  vector<int> results;
  int cur, tmp;
  long long cur_weight, tmp_weight;
  bool visit[100001] = {false, };
  queue<truck> q;
  q.push(truck(src, MAX_WEIGHT));
  visit[src] = true;

  while (!q.empty()) {
    cur = q.front().cur;
    cur_weight = q.front().weight;
    q.pop();

    for (auto next : edges[cur]) {
      tmp = next.first;
      tmp_weight = next.second;
      if (!visit[tmp]) {
	visit[tmp] = true;
	tmp_weight = min(cur_weight, tmp_weight);
	q.push(truck(tmp, tmp_weight));
	if (tmp == dst)
	  results.push_back(tmp_weight);
      }
    }
  }
  int maxx = 0;
  for (auto num : results)
    maxx = max(maxx, num);
  return maxx;
}

int main () {
  In();
  long long result = bfs();
  printf("%lld\n", result);
  
  return 0;
}
