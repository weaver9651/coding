#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int Map[15][15];

int findMax() {
  int maxx = 0;
  for (int i = 0; i + M -1 < N; i++) {
    for (int j = 0; j + M -1 < N; j++) {
      int tmp = 0;
      for (int k = 0; k < M*M; k++) {
	tmp += Map[k/M + i][k%M + j];
      }
      maxx = max(maxx, tmp);
    }
  }
  return maxx;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
	scanf("%d", &Map[i][j]);
      }
    } // Map input end

    printf("#%d %d\n", tc+1, findMax());
    
  } // tc end

  return 0; 
}
