#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[300];
int tot[300][3];
int N;

void In() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
}

int max(int a, int b, int c) {
  if (a > b) {
    if (a > c)
      return a;
    else
      return c;
  }
  else {
    if (b > c)
      return b;
    else
      return c;
  }
}

int findMax() {
  // base cases
  tot[0][0] = arr[0];
  tot[0][1] = arr[0];
  tot[0][2] = arr[0];
  if (N == 1)
    return tot[0][1];
  
  tot[1][0] = arr[0];
  tot[1][1] = arr[0] + arr[1];
  tot[1][2] = arr[0] + arr[1];
  if (N == 2)
    return tot[1][1];
  
  tot[2][0] = tot[1][2];
  tot[2][1] = tot[0][0] + arr[2];
  tot[2][2] = tot[1][2] + arr[2];
 
  
  for (int i = 3; i < N; i++) {
    tot[i][0] = tot[i-1][2];
    tot[i][1] = tot[i-1][0] + arr[i];
    tot[i][2] = tot[i-1][1] + arr[i];
  }
    return max(tot[N-1][0], tot[N-1][1], tot[N-1][2]);
}

int main () {
  In();
  int result = findMax();

  printf("%d\n", result);
  
  return 0;
}
