#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> times) {
  vector<long long> num(times.size(), 0);
  sort(times.begin(), times.end());

  long long new_n = n;
  long long back = times.back();
  long long maxx = times.back() * new_n / times.size();
  long long minn = times[0] * new_n / times.size();
  long long midd = (maxx + minn) / 2;
  long long cur_time = midd;
  
  while (true) {
    long long total = 0;
    for (int i = 0; i < times.size(); i++) {
      num[i] = cur_time / times[i];
      total += num[i];
      if (total >= n)
	break;
    }

    if (total >= n && maxx == minn)
      break;
 
    if (total >= n) {
      maxx = midd;
      midd = (minn+maxx)/2;
    }
    else { // total < n
      if (midd == minn) {
	minn = maxx;
	midd = maxx;
      }
      else {
	minn = midd;
	midd = (minn+maxx)/2;
      }
    }
    cur_time = midd;
  } 
  
  return cur_time;
}

int main () {
  vector<int> input;
  input.push_back(1);
  input.push_back(1);
  input.push_back(1);
  input.push_back(999999999);
  long long result = solution(1000000000, input);
  cout << result << endl;
  
  return 0;
}
