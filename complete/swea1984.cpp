#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    int tmp;
    int maxx = 0;
    int minn = 10000;
    double sum = 0;
    for (int i = 0; i < 10; i++) {
      scanf("%d", &tmp);
      sum += tmp;
      if (minn > tmp)
	minn = tmp;
      if (maxx < tmp)
	maxx = tmp;
    }
    sum = sum - minn - maxx;
    printf("#%d %d\n", tc+1, (int)round(sum / 8));
  }
  
  return 0;
}
