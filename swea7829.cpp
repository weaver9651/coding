#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void makeEmpty(vector<int> &s) {
  while (!s.empty()) {
    s.pop_back();
  }
}

int main () {
  int N;
  scanf("%d", &N);

  for (int tc = 1; tc <= N; tc++) {
    int tmp, start, end;
    vector<int> s;

    int P;
    scanf("%d", &P);
  
    for (int i = 0; i < P; i++) {
      scanf("%d", &tmp);
      s.push_back(tmp);
    }
    sort(s.begin(), s.end());
  
    if (P % 2 == 0) { // even number
      start = s[0];
      end = s[P-1];
    }
    else { // odd number
      start = s[P/2];
      end = s[P/2];
    }
    int result = start * end;
    printf("#%d %d\n", tc, result);
  }
  
  return 0;
}
