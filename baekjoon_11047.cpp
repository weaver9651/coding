#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> nums;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    nums.push_back(num);
  }
  sort(nums.begin(), nums.end(), greater<int>());

  int result = 0;
  int index = 0;
  while (K) {
    if (nums[index] > K) {
      index++;
      continue;
    } else {
      K -= nums[index];
      result++;
    }
  }
  cout << result << endl;
  
  return 0;
}
