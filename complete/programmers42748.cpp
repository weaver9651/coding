#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int> > commands) {
  vector<int> answer;
  int i, j, k;
  for (auto command : commands) {
    i = command[0] - 1;
    j = command[1] - 1;
    k = command[2] - 1;
    vector<int> tmp;
    vector<int>::iterator it = array.begin();
    tmp.resize(j - i + 1);
    copy(it + i, it + j + 1, tmp.begin());
    sort(tmp.begin(), tmp.end());
    answer.push_back(tmp[k]);
  }
  return answer;
}

int main () {
  vector<int> array = {1, 5, 2, 6, 3, 7, 4};
  vector<vector<int> > commands = { {2, 5, 3},
				    {4, 4, 1},
				    {1, 7, 3} };
  vector<int> result;
  result = solution(array, commands);
  for (auto x : result)
    cout << x << endl;
  
  return 0;
}
