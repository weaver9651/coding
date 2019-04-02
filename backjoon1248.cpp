#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char S[10][10];
vector<int> A(11);
int N;

void In() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      cin >> S[i][j];
    }
  }

  for (int i = 0; i <= 10; i++) {
    A[i] = i;
  }
}

int signToInt(char sign) {
  if (sign == '-')
    return -1;
  else if (sign == '+')
    return 1;
  else return 0;
}

int calc(int i, int j) {
  int result = 0;
  for (int k = i; k <= j; k++) {
    result += signToInt(S[k][k]) * A[k];
  }
  return result;
}

void findAns(){
  sort(A.begin(), A.end());
  int tmp;
  int flag;
  do {
    if (A[0] == 1 && A[1] == 3 && A[2] == 2 && A[3] == 4 )
      cout << "";
    flag = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
	tmp = calc(i, j);
	if (((tmp > 0) ? 1 : ((tmp < 0) ? -1 : 0)) != signToInt(S[i][j])) {
	  flag = 1;
	  break;
	}
      }
      if (flag == 1)
	break;
    }
    if (flag == 0)
      break;
  } while (next_permutation(A.begin(), A.end()));
}

int main () {
  In();
  findAns();
  for (int i = 0; i < N; i++) {
    cout << signToInt(S[i][i])*A[i] << " ";
  }
  cout << endl;
  
  return 0;
}
