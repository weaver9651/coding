#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

/*
연속으로 최대한 많은 땅 투자
N : 주어지는 땅
M : 투자 받은 돈
땅 가격이 N개 주어짐
*/

int counter = 0;
int N, M;

void In() {
  int tmp;
  int result = 0;
  int index = 0;
  scanf("%d%d", &N, &M);
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    arr[i] = tmp;
    result += tmp;
    if (result == M)
      counter++;
    else {
      while (result > M) {
	result -= arr[index];
	index++;
      }
      if (result == M)
	counter++;
    }
  }
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    counter = 0;
    In();
    printf("#%d %d\n", tc, counter);  
  }

  return 0;
}
