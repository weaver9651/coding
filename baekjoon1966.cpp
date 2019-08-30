#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int N, A;
    int tmp;
    scanf("%d%d", &N, &A);
    vector<int> s;
    queue<int> q;
    queue<bool> t;
    for (int i = 0; i < N; i++) {
      scanf("%d", &tmp);
      s.push_back(tmp);
      q.push(tmp);
      if (i == A)
	t.push(true);
      else
	t.push(false);
    }

    sort(s.begin(), s.end());
    int counter = 0;
    int pri;
    bool target;
    while (true) {
      pri = q.front();
      target = t.front();
      q.pop();
      t.pop();
      if (pri < s.back()) {
	q.push(pri);
	t.push(target);
      }
      else {
	s.pop_back();
	counter++;
	if (target)
	  break;
      }
    }
  
    printf("%d\n", counter);
  }
  
  return 0;
}
