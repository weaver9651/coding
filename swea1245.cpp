#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int N;
double loc[11];
double weight[11];

void In() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lf", &loc[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%lf", &weight[i]);
  }
}

double calc(int a, int b) {
  double w_a = weight[a];
  double w_b = weight[b];
  double loc_a = loc[a];
  double loc_b = loc[b];
  double l = loc_b - loc_a;
  double k = sqrt(w_a/w_b);
  double m = l*k/(1+k);
  return loc_a + m;
}

void findAns(vector<double> &results) {
  double tmp;
  for (int i = 0, j = 1; j < N; i++, j++) {
    tmp = calc(i, j);
    results.push_back(tmp);
  }
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    In();
    vector<double> results;
    findAns(results);
    printf("#%d ", tc);
    for (int i = 0; i < N-1; i++) {
      printf("%.10lf ", results[i]);
    }
    printf("\n");
  }
  
  return 0;
}
