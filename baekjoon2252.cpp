#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> *nextNode;
vector<int> *prevNode;
vector<int> ans;
vector<bool> visit;

void In() {
  scanf("%d%d", &N, &M);
  visit.assign(N+1, false);
  nextNode = new vector<int>[N+1];
  prevNode = new vector<int>[N+1];
  int from, to;
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &from, &to);
    nextNode[from].push_back(to);
    prevNode[to].push_back(from);
  }
}

void findAns() {
  int visitCnt = 0;
  queue<int> q;
  for (int i = 1; i <= N; i++) {
    if (!visit[i] && prevNode[i].empty()) {
      visit[i] = true;
      visitCnt++;
      q.push(i);
    }
  }

  int cur;
  while (!q.empty()) {
    cur = q.front();
    q.pop();
    ans.push_back(cur);

    for (vector<int>::iterator it = nextNode[cur].begin();
	 it != nextNode[cur].end(); it++) {
      int index = *it;
      for (vector<int>::iterator iter = prevNode[index].begin();
	   iter != prevNode[index].end(); iter++) {
	int target = *iter;
	if (target == cur) {
	  prevNode[index].erase(iter);
	  if (prevNode[index].empty()) {
	    visit[index] = true;
	    visitCnt++;
	    q.push(index);
	  }
	  break;
	}
      } // endfor iter
    } // endfor it
  } // endwhile

  for (vector<int>::iterator it = ans.begin();
       it != ans.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
}

int main() {
  In();
  findAns();
  
  return 0;
}
