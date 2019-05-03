#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int Map[100] = {0, };
const int N = 100;

void Out() {
  for (int i = 0; i < N; i++) {
    printf("%d ", Map[i]);
  }
  cout << endl;
}

void dump(int num) {
  for (int k = 0; k < num; k++) {
    int hindex;
    for (int i = 0; i < N - 1; i++) {
      if (Map[i] > Map[i+1]) {
	hindex = i;
	break;
      }
    }
    int lindex;
    for (int i = N-1; i > 0; i--) {
      if (Map[i] < Map[i-1]) {
	lindex = i;
	break;
      }
    }
    Map[hindex]--;
    Map[lindex]++;
  }

  return;
}

int mndiff() {
  int maxx = 0;
  int minn = 10000;
  for (int i = 0; i < N; i++) {
    maxx = max(maxx, Map[i]);
    minn = min(minn, Map[i]);
  }
  return maxx - minn;
}

int main () {
  for (int tc = 0; tc < 10; tc++) {
    int dumpN;
    cin >> dumpN;
    for (int i = 0; i < N; i++) {
      scanf("%d", &Map[i]);
    }
    sort(Map, Map + 100);
    reverse(Map, Map + 100);
    dump(dumpN);
    printf("#%d %d\n", tc+1, mndiff());
  }
  
  return 0;
}
