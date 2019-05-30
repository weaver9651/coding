#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
long long result;
int Map[10][100];

char numToChar(int num) {
  char result = '0' + num;
  return result;
}

int leaves(int num, int depth) {
  for (int i = 0; i < 10; i++) {
    Map[i][0] = 1;
  }
  
  for (int j = 1; j <= depth; j++) {
    for (int i = 0; i <= num; i++) {
      if (i == 0) {
	Map[i][j] = Map[i+1][j-1];
      }
      else if (i == 9) {
	Map[i][j] = Map[i-1][j-1];
      }
      else {
	Map[i][j] = Map[i+1][j-1] + Map[i-1][j-1];
      }
      
      if (i == num && j == depth)
	return Map[i][j];
    }
  }
}

int dist(int cur_num, int visit) {
  int maxx = 0;
  int tmp;
  for (int i = 0; i < 10; i++) {
    if (!(visit & (1 << i))) {
      tmp = abs(cur_num - i);
      maxx = max(tmp, maxx);
    }
  }
  return maxx;
}

void findAns(string num, int cur_num, int counter, int visit) {
  // visit을 만족시켰을 때 자동으로 계산하는 것 짜기
  if (visit == ((1 << 10) - 1) && (counter < N)) {
    result += leaves(cur_num, N - counter);
    return;
  }
  // 앞으로 절대 visit을 만족시킬 수 없을 때 return 하는 것 짜기
  if (visit != ((1 << 10) - 1) && dist(cur_num, visit) > (N - counter)) {
    return;
  }

  
  if (counter == N) {
    if (visit == ((1 << 10) - 1)) {
      result++;
      return;
    }
    else
      return;
  }
  string num1 = num;
  string num2 = num;
  int tmp1 = cur_num + 1;
  int tmp2 = cur_num - 1;
  num1.append(1, numToChar(tmp1));
  num2.append(1, numToChar(tmp2));
  if (tmp1 >= 0 && tmp1 <= 9) {
    findAns(num1, tmp1, counter+1, visit | (1 << tmp1));
  }
  if (tmp2 >= 0 && tmp2 <= 9) {
    findAns(num2, tmp2, counter+1, visit | (1 << tmp2));
  }
    
}

int main () {
  cin >> N;
  for (int i = 1; i <= 9; i++) {
    string num;
    num.append(1, numToChar(i));
    findAns(num, i, 1, 1 << i);
  }
  cout << result << endl;
  
  return 0;
}
