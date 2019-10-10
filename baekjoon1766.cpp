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
  queue<int> q;
  vector<bool> visit(N+1, false);
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0)
      q.push(i);
    visit[i] = true;
  }

  int cur;
  while(!q.empty()) {
    cur = q.front();
    q.pop();
    ans.push_back(cur);

    int target;
    for (vector<int>::iterator it = nextNode[cur].begin();
	 it != nextNode[cur].end(); it++) {
      target = *it;
      indegree[target]--;
      if (indegree[target] == 0) {
	q.push(target);
	visit[target] = true;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
}

int main() {
  In();
  findAns();
  
  return 0;
}
