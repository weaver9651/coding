#include <iostream>
#include <cstdio>

using namespace std;

int main () {
  int N;
  int B, C;
  cin >> N;
  int *A = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  cin >> B >> C;

  // find the number of supervisor
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int remain = A[i] - B;
    if (remain <= 0) {
      ans += 1;
    }
    else {
      int counter = remain / C;
      if (remain % C) {
	ans += counter+2;
      }
      else {
	ans += counter+1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
