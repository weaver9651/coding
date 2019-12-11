#include <iostream>
using namespace std;

int price[10001];
double ratio[10001];
int N;

void In() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> price[i];
    ratio[i] = price[i] / i;
  }
}

int findRatio(int range) {
  int index = 0;
  double maxx = 0;
  for (int i = 1; i <= range; i++) {
    if (ratio[i] > maxx) {
      index = i;
      maxx = ratio[i];
    }
  }
  return index;
}

int findAns() {
  int result = 0;
  int remain = N;
  while (remain) {
    int index = findRatio(remain);
    result += price[index];
    remain -= index;
  }
  return result;
}

int main() {
  In();
  int result = findAns();
  cout << result << endl;
  
  return 0;
}
