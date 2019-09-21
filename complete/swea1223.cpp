#include <bits/stdc++.h>
using namespace std;

int main () {
  const int T = 10;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    scanf("%d", &N);
    vector<int> s;
    char tmp;
    char oper = '0';
    long long result = 0;
    scanf("%c", &tmp); // remove newline
    scanf("%c", &tmp);
    s.push_back(tmp - '0');
    for (int i = 1; i < N / 2 + 1; i++) {
      scanf("%c", &oper);
      scanf("%c", &tmp);
      if (oper == '+') {
	s.push_back(tmp - '0');
      }
      else if (oper == '*') {
	int tmp1 = s.back();
	int tmp2 = tmp - '0';
	s.pop_back();
	s.push_back(tmp1*tmp2);
      }
    }

    for (auto x : s) {
      result += x; 
    }
    printf("#%d %lld\n", tc, result);
  }  
  return 0;
}
