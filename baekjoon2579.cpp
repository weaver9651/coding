#include <iostream>
#include <cstdio>

using namespace std;

int score[301];
int maxx = 0;
bool chain[301] = {false, };
int N;

void In() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &score[i]);
  }
}

void dp(int cur, int counter, int index) {
  if (index == N) {
    maxx = max(maxx, cur);
    return;
  }
  if (index > N)
    return;
  
  if (counter != 2) {
    dp(cur+score[index+1], counter+1, index+1);
  }
  dp(cur+score[index+2], 1, index+2);
}

void findAnswer() {
  dp(score[1], 0, 1);
}

int main () {
  In();
  findAnswer();
  cout << maxx << endl;
  
  return 0;
}
