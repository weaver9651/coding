#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void init(vector<int> &nums) {
  while(!nums.empty())
    nums.pop_back();
}

int main () {
  int T;
  scanf("%d", &T);
  vector<int> nums;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    int tmp, H;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &tmp);
      nums.push_back(tmp);
    }
    sort(nums.begin(), nums.end());
    for (int h = nums.size(); h > 0; h--) {
      if (nums[nums.size()-h] >= h) {
	H = h;
	break;
      }
    }
    printf("#%d %d\n", tc, H);
    init(nums);
  }
  
  return 0;
}
