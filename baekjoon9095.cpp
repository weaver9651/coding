#include <iostream>
#include <cstdio>

using namespace std;

int maxx = 0;

void dp(int cur, int goal) {
  if (cur == goal) {
    maxx++;
    return;
  }
  else if (cur > goal)
    return;

  dp(cur+1, goal);
  dp(cur+2, goal);
  dp(cur+3, goal);

  return;
}

void findAnswer(int goal) {
  dp(1, goal);
  dp(2, goal);
  dp(3, goal);

  return;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    maxx = 0;
    findAnswer(N);
    cout << maxx << endl;
  }
  
  return 0;
}
