#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int NtoDec(int N, long long X) {
  long long result = 0;
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
    int N;
    long long X;
    cin >> N >> X;
    long long result = 0;
    result = NtoDec(N, X) % (N-1);
    printf("#%d %lld\n", tc+1, result);
  }
  
  return 0;
}
