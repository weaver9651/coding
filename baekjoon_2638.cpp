#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int Map[101][101] = {
    0,
};
int cheeseCnt = 0;
vector<pii> cheeseList;
vector<pii> removeCand;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0 , 0};

void In() {
  cin >> N >> M;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tmp;
      Map[i][j] = tmp;
      if (tmp == 1) {
        cheeseCnt++;
        cheeseList.push_back(pii(i, j));
      }
    }
  }
}

bool isInside(int y, int x) {
  return (x >= 0 && x < M && y >= 0 && y < N);
}

void paint(int y, int x) {
  // 가장 자리에는 치즈가 무조건 없음
  int c_y, c_x, n_y, n_x;
  queue<pii> q;
  vector<bool> visitTmp(M, false);
  vector<vector<bool> > visit(N, visitTmp);
  visit[y][x] = true;
  Map[y][x] = -1;
  q.push(pii(y, x));

  while (!q.empty()) {
    c_y = q.front().first;
    c_x = q.front().second;
    q.pop();

    for (int d = 0; d < 4; d++) {
      n_y = c_y + dy[d];
      n_x = c_x + dx[d];
      if (isInside(n_y, n_x) && !visit[n_y][n_x] && Map[n_y][n_x] == 0) {
        visit[n_y][n_x] = true;
        Map[n_y][n_x] = -1;
        q.push(pii(n_y, n_x));
      }
    }
  }
}

bool isMelt(int y, int x) {
  int counter = 0;
  int n_y, n_x;
  for (int d = 0; d < 4; d++) {
    n_y = y + dy[d];
    n_x = x + dx[d];
    if (Map[n_y][n_x] == -1) {
      counter++;
    }
  }
  return counter >= 2;
}

void melt() {
  for (auto it = cheeseList.begin(); it != cheeseList.end();) {
    if (isMelt(it->first, it->second)) {
      removeCand.push_back(pii(it->first, it->second));
      cheeseCnt--;
      cheeseList.erase(it);
    } else {
      it++;
    }
  }
}

void removeAndPaint() {
  int n_y, n_x;
  for (auto p : removeCand) {
    Map[p.first][p.second] = -1;
    for (int d = 0; d < 4; d++) {
      n_y = p.first + dy[d];
      n_x = p.second + dx[d];
      if (isInside(n_y, n_x) && Map[n_y][n_x] == 0) {
        paint(n_y, n_x);
      }
    }
  }
}

int findAns() {
  int counter = 0;
   // 바깥 칠하기
    paint(0, 0);
  while (cheeseCnt) {
    counter++;
    // 바깥과 두 곳이상 만나면 저장해서 다음 턴에 없애기, 치즈 갯수 감소
    // 바로 지우면 계속 추가로 지울 게 일어남
    melt();
    // 치즈 지우면서 주변에 0이 있으면 그 칸에서 칠하기
    removeAndPaint();
  }
  return counter;
}

int main() {
  In();
  int result = findAns();
  cout << result << endl;

  return 0;
}