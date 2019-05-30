#include <cstdio>

using namespace std;


int findAns(int num) {
  int check = (1 << 10) - 1;
  int flag = 0;
  int tmp;
  int before;
  int counter = 0;
  while (num) {
    before = flag;
    tmp = num % 10;
    num /= 10;
    flag |= (1 << tmp);
    
    if (before != flag)
      counter++;
  }
  
  return counter;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int N;
    scanf("%d", &N);
    printf("#%d %d\n", tc, findAns(N));
  }
  
  return 0;
}
