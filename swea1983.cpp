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
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N, K;
    scanf("%d%d", &N, &K);
    double *students = new double[N];
    double tmp;
    for (int i = 0; i < N; i++) {
      students[i] = 0;
      for (int tmpi = 0 ; tmpi < 3; tmpi++) {
	scanf("%lf", &tmp);
	if (tmpi == 0)
          students[i] += tmp * 0.35;
	else if (tmpi == 1)
	  students[i] += tmp * 0.45;
	else if (tmpi == 2)
	  students[i] += tmp * 0.2;
      }
      cout << students[i] << endl;
    }

    double pivot = students[K-1];
    int counter = 0;
    for (int i = 0; i < N; i++) {
      if (students[i] > pivot)
	counter++;
    }
    int pre = counter / (N / 10);
    cout << "#" << tc+1 << " " << grades[pre] << endl;
  }
  
  return 0;
}
