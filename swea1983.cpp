#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string grades[10] = {
  "A+", "A0", "A-",
  "B+", "B0", "B-",
  "C+", "C0", "C-",
  "D0"
};

int main () {
  int T;
  for (int tc = 0; tc < T; tc++) {
    int N, K;
    scanf("%d%d", &N, &K);
    int *students = new int[N];
    int tmp;
    for (int i = 0; i < N; i++) {
      students[i] = 0;
      for (int tmpi = 0 ; tmpi < 3; tmpi++) {
	scanf("%d", &tmp);
	students[i] += tmp;
      }
    }

    int pivot = students[K-1];
    int counter = 0;
    for (int i = 0; i < 10; i++) {
      if (students[i] > pivot)
	counter++;
    }
    int pre = counter / (N / 10);
    cout << grades[pre] << endl;
  }
  
  return 0;
}
