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
    }
    else if (sign[i][index] < 0) {
      if (sum >= 0) return false;
    }
    else if (sign[i][index] < 0) {
      if (sum <= 0) return false;
    }
  }
  return true;
}


// && 연산 시 check를 앞에 둠으로써 만약 check에서 false가 나면 뒤는 자동으로 계산하지 않음.
bool go(int index) {
  // 마지막 index를 넘어서면 정상종료
  if (index == N) return true;

  // sign이 0인 경우는 무조건 0을 할당하고 종료(다음 index의 정상종료값을 찾음)
  if (sign[index][index] == 0) {
    ans[index] = 0;
    return check(index) && go(index + 1);
  }

  // sign이 0이 아니면 1부터 숫자를 하나씩 넣어가면서 다음 index를 찾음(DFS)
  for (int i = 1; i <= 10; i++) {
    ans[index] = sign[index][index] * i;
    if (check(index) && go(index + 1)) return true;
  }
  return false;
}

int main() {
  In();
  go(0);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

  return 0;
}
