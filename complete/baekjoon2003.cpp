#include <iostream>
#include <cstdio>

using namespace std;

int findNum(int N, int M, int arr[]) {
  int counter = 0;
  int now = arr[0];
  for (int i = 0, j = 0; i < N; i++) {
    while (j < N) {
      if (now == M) {
	counter++;
      }
      else if (now > M) {
	now -= arr[i];
	break;
      }
      j++;
      now += arr[j];
    }
  }
  return counter;
}

int main() {
  int N, M;
  cin >> N >> M;

  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }
  cout << findNum(N, M, arr) << endl;

  return 0;
}
