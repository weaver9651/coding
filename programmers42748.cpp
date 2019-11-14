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
    k = command[2];
    vector<int> tmp;
    vector<int>::iterator it = array.begin();
    copy(it + i, it + j, tmp.begin());
    sort(tmp.begin(), tmp.end());
    answer.push_back(tmp[k]);
  }
  return answer;
}
