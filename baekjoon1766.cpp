#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

/*
1 ~ N
 */

int N, M;
int *indegree;
vector<int> *nextNode;
vector<int> ans;

void In() {
  scanf("%d%d", &N, &M);
  indegree = new int[N+1];
  for (int i = 0; i <= N; i++)
    indegree[i] = 0;
  nextNode = new vector<int>[N+1];
  int from, to;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &from, &to);
    nextNode[from].push_back(to);
    indegree[to]++;
  }
}

void findAns() {
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<bool> visit(N+1, false);
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0)
      pq.push(i);
    visit[i] = true;
  }

  int cur;
  while(!pq.empty()) {
    cur = pq.top();
    pq.pop();
    ans.push_back(cur);

    int target;
    for (vector<int>::iterator it = nextNode[cur].begin();
	 it != nextNode[cur].end(); it++) {
      target = *it;
      indegree[target]--;
      if (indegree[target] == 0) {
	pq.push(target);
	visit[target] = true;
      }
    }
  }

  for (auto x : ans) {
    printf("%d ", x);
  }
  printf("\n");
}

int main() {
  In();
  findAns();
  
  return 0;
}
