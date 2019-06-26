#include <iostream>
#include <cstdio>

using namespace std;

int data[41][2] = {0, }; // column  0 for 0, 1 for 1

void findAnswer() {
  for (int i = 0; i <= 40; i++) {
    if (i == 0) {
      data[i][0] = 1;
      data[i][1] = 0;
    }
    else if (i == 1) {
      data[i][0] = 0;
      data[i][1] = 1;
    }
    else {
      data[i][0] = data[i-1][0] + data[i-2][0];
      data[i][1] = data[i-1][1] + data[i-2][1];
    }
  }
}

int main () {
  findAnswer();
  int T;
  scanf("%d", &T);
  int N;
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    printf("%d %d\n", data[N][0], data[N][1]);
  }
  
  return 0;
}
