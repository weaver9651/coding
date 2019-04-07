#include <iostream>
#include <algorithm>

using namespace std;

int findMin(int N, int S, int arr[]) {
  int minn = 100001;
  int now = arr[0];
  for (int i = 0, j = 0; i < N; i++) {
    while (j < N) {
      if (now >= S) {
	minn = min(minn, j - i + 1);
	now -= arr[i];
	break;
      }
      else {
	j++;
	now += arr[j];
      }
    }
  }
  if (minn == 100001)
    return 0;
  else
    return minn;
}

int main () {
  int N, S;
  cin >> N >> S;
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  cout << findMin(N, S, arr) << endl;

  return 0;
}
