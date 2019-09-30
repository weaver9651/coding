#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

long long permutation(int n, int r) {
  long long result = 1;
  for (int i = 0; i < r; i++) {
    result *= (n-i);
  }
  return result;
}

deque<pair<int,int> >::iterator findMin(deque<pair<int,int> > &target) {
  deque<pair<int,int> >::iterator pos;
  long long minn = 1000000000000;
  for (deque<pair<int,int> >::iterator it = target.begin();
       it != target.end(); it++) {
    long long tmp = permutation(it->first, it->second);
    if(tmp < minn) {
      minn = tmp;
      pos = it;
    }
  }
  return pos;
}

long long solution(int n) {
  long long answer = 0;
  int counter = 0;
  int tmp;
  deque<pair<int,int> > cands;
  cands.push_back(make_pair(2, 2));
  while(counter < n)  {
    counter++;
    deque<pair<int,int> >::iterator it = findMin(cands);
    tmp = it->first + 1;
    if (counter == n) {
      answer = permutation(it->first, it->second);
      break;
    }
    if (abs(it->first - it->second) <= 1) {
      cands.erase(it);
    }
    else
      (it->second)++;
    if (cands.empty() || cands.back().second != 2)
      cands.push_back(make_pair(tmp, 2));
  }
  cout << cands.size() << endl;
  return answer;
}

int main () {
  int N;
  cin >> N;
  long long result = solution(N);
  cout << result << endl;
  return 0;
}
