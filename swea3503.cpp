#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int N;

void In (vector<int> &arr) {
  scanf("%d", &N);
  int tmp;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    arr.push_back(tmp);
  }
}


int findAns(vector<int> arr) {
  int minn = 100000;
  int cur_max = 0;
  
  sort(arr.begin(), arr.end());
  do {
    cur_max = 0;
    for (int i = 0, j = 1; j < N; i++, j++) {
      cur_max = max(cur_max, abs(arr[i]-arr[j]));
      if (cur_max > minn) break;
    }
    cur_max = max(cur_max, abs(arr[0]-arr[N-1]));
    minn = min(minn, cur_max);
  } while (next_permutation(arr.begin(), arr.end()));
 
  return minn;
}

int main () {
  int T;
  scanf("%d", &T);

  for (int tc = 1; tc <= T; tc++) {
    vector<int> arr;
    In(arr);
    int result = findAns(arr);
    printf("#%d %d\n", tc, result);
  }
  
  return 0;
}
