#include <iostream>
#include <cstdio>

using namespace std;

int factorial(int num) {
  if (num == 0)
    return 1;
  
  int result = 1;
  for (int i = 1; i <= num; i++) {
    result *= i;
  }

  return result;
}

int combination(int n, int r) {
  if (n < r) {
    cout << "wrong input" << endl;
    return 0;
  }

  int result;
  result = factorial(n) / (factorial(n-r) * factorial(r));
  
  return result;
}

void pascal(int num) {
  printf("%d\n", 1);
  for (int k = 1; k < num; k++) {
    for (int i = 0; i <= k; i++) {
      printf("%d ", combination(k, i));
    }
    cout << "\n";
  }
}

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N;
    cin >> N;
    cout << "#" << tc+1 << endl;
    pascal(N);
  }
  
  return 0;
}
