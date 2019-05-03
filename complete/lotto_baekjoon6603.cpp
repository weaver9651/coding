#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void ps(int arr[], bool visit[],  int N, int counter, int index) {
  if (counter == 6) {
    for (int i = 0; i < N; i++) {
      if (visit[i]) {
	printf("%d ", arr[i]);
      }
    }
    cout << endl;
    return;
  }
  if (index >= N) {
    return;
  }

  visit[index] = true;  
  ps(arr, visit, N, counter+1, index+1);
  visit[index] = false;
  ps(arr, visit, N, counter, index+1);

  return;
}

void In() {
  int arr[13];
  while (true) {
    int N;
    cin >> N;
    if (N == 0)
      break;
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
    }
    bool visit[13] = {false, };
    ps(arr, visit, N, 0, 0);
    cout<< endl;
  }
}

int main () {
  In();
  
  return 0;
}
