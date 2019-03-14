#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int Map[100][100];
int T, N;
int Nlocation[10][2];
int com_y, com_x;
int home_y, home_x;
int minn = 10000000;
bool visit[10] = {false, };
int results[10];


void In() {
  scanf("%d", &N);
  scanf("%d", &com_y);
  scanf("%d", &com_x);
  scanf("%d", &home_y);
  scanf("%d", &home_x);
  
  for (int i = 0; i < N; i++) {
    scanf("%d", &Nlocation[i][0]);
    scanf("%d", &Nlocation[i][1]);
  }
}

void findMin(int cur, int dist, int counter) {
  if (counter == N) {
    // last to home
    minn = min(minn, dist + abs(Nlocation[cur][0] - home_y) + abs(Nlocation[cur][1] - home_x));
    return;
  }

  visit[cur] = true;
  for (int i = 0; i < N; i++) {
    if (visit[i])
      continue;

    findMin(i, dist + abs(Nlocation[cur][0] - Nlocation[i][0]) + abs(Nlocation[cur][1] - Nlocation[i][1]), counter + 1);
  }
  visit[cur] = false;
}

void clear() {
  for (int i = 0; i < 10; i++)
    visit[i] = false;
  minn = 10000000;
}

int main () {
  cin >> T;
  for (int tc = 0 ; tc < T; tc++) {
    In();
    for (int i = 0; i < N; i++) {
      int c2i = abs(com_y - Nlocation[i][0]) + abs(com_x - Nlocation[i][1]);
      findMin(i, c2i, 1);
    }
    results[tc] = minn;
    clear();
  }

  for (int i = 0; i < T; i++)  {
    cout << "#" << i+1 << " " << results[i] << endl;
  }
  
  return 0;
}
