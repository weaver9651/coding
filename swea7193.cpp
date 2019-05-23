#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int NtoDec(int N, int X) {
  int result = 0;
  int counter = 0;
  while (X) {
    result += (X % 10) * pow(N, counter);
    X /= 10;
    counter++;
  }
  
  return result;
}

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N, X;
    cin >> N >> X;
    int result = 0;
    result = NtoDec(N, X) % (N-1);
    printf("#%d %d\n", tc+1, result);
  }
  
  return 0;
}
