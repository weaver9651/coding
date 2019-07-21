#include <iostream>

using namespace std;

int select(bool *arr, int start, int N) {
  for (int i = start; i <= N; i++) {
    if (arr[i])
      return i;
  }
  return -1;
}

int main () {
  int N, A, B;
  cin >> N >> A >> B;

  bool *arr = new bool[N+1];
  for (int i = 1; i <= N; i++) {
    arr[i] = true;
  }

  bool flag = true;
  int first, second;
  int base = 1;
  while (flag) {
    first = select(arr, base, N);
    second = select(arr, first+1, N);
  }
  
  return 0;
}
