#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int reg[10000];
bool visit[10000] = { false, };
int from[10000];
char how[10000];

void init() {
  for (int i = 0; i < 10000; i++) {
    visit[i] = false;
  }
}

int makeD(int num) {
  return num * 2 % 10000;
}

int makeS(int num) {
  if (num == 0)
    return 9999;
  else
    return num - 1;
}

int makeL(int num) {
  int d1 = num / 1000;
  return (num - d1 * 1000) * 10 + d1;
}

int makeR(int num) {
  int d4 = num % 10;
  return (num / 10) + d4 * 1000;
}

void print(int n, int m) {
  if (n != m) {
    print(n, from[m]);
    cout << how[m];
  }
}

void findPath(int src, int dst) {
  int cur = src;
  queue<int> q;
  q.push(cur);

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    if (cur == dst)
      break;

    if (!visit[makeD(cur)]) {
      q.push(makeD(cur));
      visit[makeD(cur)] = true;
      from[makeD(cur)] = cur;
      how[makeD(cur)] = 'D';
    }

    if (!visit[makeS(cur)]) {
      q.push(makeS(cur));
      visit[makeS(cur)] = true;
      from[makeS(cur)] = cur;
      how[makeS(cur)] = 'S';
    }

    if (!visit[makeL(cur)]) {
      q.push(makeL(cur));
      visit[makeL(cur)] = true;
      from[makeL(cur)] = cur;
      how[makeL(cur)] = 'L';
    }

    if (!visit[makeR(cur)]) {
      q.push(makeR(cur));
      visit[makeR(cur)] = true;
      from[makeR(cur)] = cur;
      how[makeR(cur)] = 'R';
    }

  }
  print(src, dst);
}

int main() {
  int A, B;
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> A >> B;
    findPath(A, B);
    cout << endl;
    init();
  }

  return 0;
}
