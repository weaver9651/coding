#include <iostream>

typedef unsigned long long ull;

using namespace std;

int main () {
  int T, N;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cin >> N;
    ull left = (N-1)*(N-1)*2 + 1;
    ull right = 2*N*N - 1;
    cout << "#" << tc << " " << left << " " << right << endl;
  }
  
  return 0;
}
