#include <iostream>
#include <cstdio>

using namespace std;

int test(int num) {
  int result = 0;
  for (int i = 1; i <= num; i++) {
    if (i % 2)
      result += i;
    else
      result += i*(-1);
  }
  return result;
} 

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N;
    cin >> N;
    printf("#%d %d\n", tc+1, test(N));
  }
  
  return 0;
}
