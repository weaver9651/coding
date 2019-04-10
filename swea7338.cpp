#include <iostream>
#include <vector>

using namespace std;

int main () {
  int T;
  cin >> T;
  vector<pair<long long, int> > results;
  long long Y;
  int M;
  long long newYear;
  int newMonth;
  const int  baseYear = 2016;
  
  for (int tc = 0; tc < T; tc++) {
    cin >> Y >> M;
    long long tot = (Y - baseYear)*12 + M;
    newYear = (tot-1) / 13 + baseYear;
    newMonth = (tot-1) % 13 + 1;
    results.push_back(make_pair(newYear, newMonth));
  }

  int i = 0;
  for (vector<pair<long long, int> >::iterator iter = results.begin(); iter != results.end(); iter++) {
    i++;
    cout << "#" << i << " " << iter->first << " " << iter->second << endl;
  }
  
  return 0;
}
