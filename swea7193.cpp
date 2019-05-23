#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int NtoDec(int N, long long X) {
  long long result = 0;
  int counter = 0;
  while (X) {
    result += (long long)((X % 10) * pow(N, counter)) % (N-1);
    X /= 10;
    counter++;
  }
  
  return result % (N-1);
}


int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N;
    long long X;
    cin >> N >> X;
    int result = 0;
    result = NtoDec(N, X);
    printf("#%d %d\n", tc+1, result);
  }
  
  return 0;
}
