#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int findNum(int N, int K) {
  int *arr = new int[N];
  vector<int> numbers;

  for (int i = 0; i < N; i++) {
    scanf("%1x", &arr[i]);
  }
  for (int k = 0; k < N / 4; k++) {
    for (int i = 0; i < 4; i++) {
      int num = 0;
      for (int j = 0; j < N / 4; j++) {
	num = num * 16 + arr[(N / 4 * i + j + k) % N];
      }
      numbers.push_back(num);
    }
  }
  sort(numbers.begin(), numbers.end(), greater<int>());
  sort(unique(numbers.begin(), numbers.end()), numbers.end());

  //// debugging
  //for (int x : numbers)
  //    cout << x << endl;
  //cout << endl;

  return numbers[K - 1];
}

int main() {
  int T;
  cin >> T;
  vector<int> results(T);

  for (int tc = 0; tc < T; tc++) {
    int N, K;
    cin >> N >> K;
    results[tc] = findNum(N, K);
  }

  int i = 0;
  for (int result : results) {
    i++;
    cout << "#"  << i << " " << result << endl;
  }

  return 0;
}
