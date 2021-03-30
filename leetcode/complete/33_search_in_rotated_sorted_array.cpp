#include <iostream>
#include <vector>

using namespace std;

int bs(vector<int> &nums, int target, int s, int l);
int search(vector<int> &nums, int target);
int findPivot(vector<int> &nums);

int main() {
  vector<int> nums = {3, 5, 1};
  int target = 3;
  int result = search(nums, target);
  cout << result << endl;

  return 0;
}

int search(vector<int> &nums, int target) {
  int last = nums.size() - 1;
  if (nums.size() <= 2) {
    if (nums.front() == target) {
      return 0;
    } else if (nums.size() == 2 && nums.back() == target) {
      return 1;
    } else {
      return -1;
    }
  }

  if (nums[0] < nums[last]) {
    return bs(nums, target, 0, last);
  }

  int pivotIndex = findPivot(nums);
  cout << "pivot: " << pivotIndex << endl;
  if (target >= nums[0]) {
    return bs(nums, target, 0, pivotIndex);
  } else {
    return bs(nums, target, pivotIndex + 1, last);
  }
}

int findPivot(vector<int> &nums) {
  int s = 0;
  int l = nums.size() - 1;
  int m;
  while (true) {
    m = (s + l) / 2;
    if (s == m || l == m)
      return m;
    if (nums[m] > nums[l]) {
      s = m;
    } else {
      l = m;
    }
  }
}

int bs(vector<int> &nums, int target, int s, int l) {
  int m;
  while (true) {
    m = (s + l) / 2;
    if (m == s || m == l) {
      if (target == nums[m]) {
        return m;
      } else if (target == nums[l]) {
        return l;
      } else if (target == nums[s]) {
        return s;
      } else {
        return -1;
      }
    }
    if (target > nums[m]) {
      s = m;
    } else {
      l = m;
    }
  }
}