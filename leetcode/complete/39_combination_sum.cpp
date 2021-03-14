#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> answer;

vector<vector<int>> combinationSum(vector<int>& candidates, int target);
void findCombination(vector<int>& candidates, int index, vector<int> &nums, int currentSum, int target);

int main() {

  vector<int> candidates = {2, 3, 6 ,7};
  int target = 7;
  combinationSum(candidates, target);
  for (auto vec : answer) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> nums;
    findCombination(candidates, 0, nums, 0, target);
    return answer;
}

void findCombination(vector<int>& candidates, int index, vector<int> &nums, int currentSum, int target) {
    if (currentSum > target) {
        return;
    }
    if (currentSum == target) {
        answer.push_back(nums);
        return;
    }
    if (index >= candidates.size()) {
        return;
    }
    
    findCombination(candidates, index + 1, nums, currentSum, target);
    int num = candidates[index];
    nums.push_back(num);
    findCombination(candidates, index, nums, currentSum + num, target);
    nums.pop_back();
    return;
}