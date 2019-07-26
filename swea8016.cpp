#include <iostream>

using namespace std;

int main () {
  int T;
  cin >> T;
  unsigned long long N;
  for (int tc = 1; tc <= T; tc++) {
    cin >> N;
    unsigned long long left, right;
    left = (N-1)*(N-1)*2 + 1;
    right = 2*N*N - 1;
    cout << "#" << tc << " " << left << " " << right << endl;
  }
  
  return 0;
}
