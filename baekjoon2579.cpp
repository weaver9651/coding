#include <iostream>
#include <cstdio>

using namespace std;

int score[301];
int maxx[301];
bool chain[301] = {false, };
int N;

int findAnswer() {
  maxx[1] = score[1];
  maxx[2] = score[2] + score[1];
  for (int i = 3; i <= N; i++) {
    bool flag = chain[i-1];
    if (flag) {
      maxx[i] = score[i] + maxx[i-2];
      chain[i] = false;
    }
    else {
      maxx[i] = score[i] + maxx[i-1];
      chain[i] = true;
    }
  }

  return maxx[N];
}

void In() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &score[i]);
  }
}

int main () {
  In();
  cout << findAnswer() << endl;  
  
  return 0;
}
