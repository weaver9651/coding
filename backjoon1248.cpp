#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sign[10][10];
int ans[10];
int N;

void In() {
  char tmp;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      cin >> tmp;
      if (tmp == '-')
	sign[i][j] = -1;
      else if (tmp == '+')
	sign[i][j] = 1;
      else if (tmp == '0')
	sign[i][j] = 0;
    }
  }
}

bool check(int index) {
  int sum = 0;
  for (int i = index; i >= 0; i--) {
    sum += ans[i];
    if (sign[i][index] == 0) {
      if (sum != 0) return false;
    } else if (sign[i][index] < 0) {
      if (sum >= 0) return false;
    } else if (sign[i][index] < 0) {
      if (sum <= 0) return false;
    }
  }
  return true;
}

bool go(int index) {
  if (index == N) return true;
  if (sign[index][index] == 0) {
      ans[index] = 0;
      return check(index) && go(index + 1);
    }
  for (int i = 1; i<= 10; i++) {
    ans[index] = sign[index][index] * i;
    if (check(index) && go(index + 1)) return true;
  }
}

int main () {
  In();
  go(0);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  
  return 0;
}
