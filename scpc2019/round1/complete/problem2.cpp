#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int R, S, E, N;
const double PI = 2*asin(1.0);

class building {
public:
  int left;
  int right;
  int height;
  
  building(int left, int right, int height) : left(left), right(right), height(height) {};
};

vector<building> bdgs;

void In() {
  scanf("%d%d%d", &R, &S, &E);
  scanf("%d", &N);

  int left, right, height;
  for (int i = 0; i < N; i++) {
    scanf("%d%d%d", &left, &right, &height);
    bdgs.push_back(building(left, right, height));
  }
}

double smallbdg(int h) {
  double result = 0;
  result += 2*R*(PI/2 - asin((R-h)/double(R)));
  result += 2*(R - sqrt(pow(R, 2) - pow(R-h, 2)));
  result -= 2*R;

  return result;
}

double bigbdg(int h) {
  double result = 0;
  result += PI*R;
  result += 2*h;
  result -= 4*R;
  
  return result;
}

void init() {
  while (!bdgs.empty()) {
    bdgs.pop_back();
  }
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    In();
    double result = 0;
    double tmp;
    for (building bdg : bdgs) {
      if (bdg.height >= R) {
	tmp = bigbdg(bdg.height);
	result += tmp;
      }
      else {
	tmp = smallbdg(bdg.height);
	result += tmp;
      }
    }

    result += E - S;

    printf("Case #%d\n%0.6f\n", tc, result);
    init();
  }
  
  return 0;
}
