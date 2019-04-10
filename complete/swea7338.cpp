#include <iostream>
#include <cstdio>

using namespace std;

int main () {
  int T;
  cin >> T;
  long long Y;
  int M;
  long long newYear;
  int newMonth;
  const int  baseYear = 2016;

  for (int tc = 0; tc < T; tc++) {
    scanf("%lld", &Y);
    scanf("%d", &M);
    long long tot = (Y - baseYear)*12 + M;
    newYear = (tot-1) / 13 + baseYear;
    newMonth = (tot-1) % 13 + 1;

    printf("#%d %lld %d\n", tc+1, newYear, newMonth);
  }

  return 0;
}
