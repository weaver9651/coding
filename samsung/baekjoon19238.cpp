#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/**
 * 오답노트
 * 1. 사람 찾을 때랑, 목적지 도착했을 때 택시 출발위치 갱신 안함
 * 2. 최초 택시 연료 주어짐에도 불구하고 실수로 15로 일괄 초기화함
 * 3. 문제에서 위치가 1-index로 주어지는데 0-index인줄 알고 진행
 * 4. visit에 true 할당하는 거 빠뜨림
 * 5. 연료 다시 충전할 때 남은 연료에서 충전한 것이 아니라 출발할 때 연료에서 충전했음
 */

typedef pair<int, int> pii;

int N, M;
long long start_fuel;
int Map[21][21];
int taxi_y, taxi_x;
int peopleMap[21][21] = {false, }; // 1-index
vector<pii> starts;
vector<pii> dests;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

class Taxi{
public:
  int y, x, fuel;
  Taxi(int y, int x, int fuel) : y(y), x(x), fuel(fuel) {}
  Taxi() {}
};

void In() {
  int num;
  scanf("%d%d%lld", &N, &M, &start_fuel);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &num);
      Map[i][j] = num;
    }
  }
  scanf("%d%d", &taxi_y, &taxi_x);
  taxi_y--;
  taxi_x--;
  int s_y, s_x, d_y, d_x;
  starts.push_back(pii(-1, -1)); // dummy
  dests.push_back(pii(-1, -1)); // dummy
  for (int i = 1; i <= M; i++) {
    scanf("%d%d%d%d", &s_y, &s_x, &d_y, &d_x);
    starts.push_back(pii(s_y-1, s_x-1));
    dests.push_back(pii(d_y-1, d_x-1));
    peopleMap[s_y-1][s_x-1] = i;
  }
}

bool isInside(int y, int x) {
  return (y >= 0 && y < N && x >= 0 && x < N);
}

vector<int> findPerson() {
  vector<int> results;
  int cur_y, cur_x, tmp_y, tmp_x, cur_f, tmp_f;
  vector<bool> visitTmp(N, false);
  vector<vector<bool> > visit(N, visitTmp);
  queue<Taxi> q;
  queue<Taxi> bufferQ;
  cur_y = taxi_y;
  cur_x = taxi_x;
  if (peopleMap[cur_y][cur_x] != 0) {
    results.push_back(peopleMap[cur_y][cur_x]);
    return results;
  }
  bufferQ.push(Taxi(cur_y, cur_x, start_fuel));
  visit[cur_y][cur_x] = true;

  while (!(q.empty() && bufferQ.empty())) {
    while (!bufferQ.empty()) {
      q.push(bufferQ.front());
      bufferQ.pop();
    }

    while (!q.empty()) { 
      cur_y = q.front().y;
      cur_x = q.front().x;
      cur_f = q.front().fuel;
      q.pop();

      for (int d = 0; d < 4; d++) {
        tmp_y = cur_y + dy[d];
        tmp_x = cur_x + dx[d];
        tmp_f = cur_f - 1;
        if (tmp_f >= 0 && isInside(tmp_y, tmp_x) && !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] == 0) {
          visit[tmp_y][tmp_x] = true;
          int personIndex = peopleMap[tmp_y][tmp_x];
          if (personIndex != 0) {
            results.push_back(personIndex);
            start_fuel = tmp_f;
            continue;
          }
          bufferQ.push(Taxi(tmp_y, tmp_x, tmp_f));
        }
      }
    }
    if (!results.empty())
      return results;
  }
  return results;
}

bool pickOneComp(int &a, int &b) {
  // 행 번호가 작은 순, 같다면 열 번호가 작은 순
  if (starts[a].first != starts[b].first) {
    return starts[a].first < starts[b].first;
  } else {
    return starts[a].second < starts[b].second;
  }
}

int pickOne(vector<int> &peopleIndex) {
  sort(peopleIndex.begin(), peopleIndex.end(), pickOneComp);
  int result = peopleIndex[0];
  peopleMap[starts[result].first][starts[result].second] = 0;
  taxi_y = starts[result].first;
  taxi_x = starts[result].second;

  return result;
}

bool ride(int personIndex) {
  int cur_y, cur_x, cur_f, tmp_y, tmp_x, tmp_f;
  vector<bool> visitTmp(N, false);
  vector<vector<bool> > visit(N, visitTmp);
  cur_y = starts[personIndex].first;
  cur_x = starts[personIndex].second;
  cur_f = start_fuel;
  visit[cur_y][cur_x] = true;
  queue<Taxi> q;
  q.push(Taxi(cur_y, cur_x, cur_f));

  while (!q.empty()) {
    cur_y = q.front().y;
    cur_x = q.front().x;
    cur_f = q.front().fuel;
    q.pop();

    for (int d = 0; d < 4; d++) {
      tmp_y = cur_y + dy[d];
      tmp_x = cur_x + dx[d];
      tmp_f = cur_f - 1;
      if (tmp_f >= 0 && isInside(tmp_y ,tmp_x) && Map[tmp_y][tmp_x] == 0 && !visit[tmp_y][tmp_x]) {
        visit[tmp_y][tmp_x] = true;
        if (tmp_y == dests[personIndex].first && tmp_x == dests[personIndex].second) {
          start_fuel = tmp_f + (start_fuel - tmp_f) * 2;
          taxi_y = tmp_y;
          taxi_x = tmp_x;
          return true;
        }
        q.push(Taxi(tmp_y, tmp_x, tmp_f));
      }
    }
  }
  return false;
}

int findAns() {
  int personNum = M;
  // 현재 위치에서 가장 가까운 고객
  while (personNum) {
    vector<int> peopleIndex = findPerson();
    if (peopleIndex.empty()) // 태울 승객까지 연료가 부족함
      return -1;
    //// 여러 명이면 행 번호가 작은, 열 번호가 작은 고객 우선순위
    int personIndex = pickOne(peopleIndex);
    // 연료가 0이 되면 움직일 수 없음
    // 도착하면 연료의 두 배가 충전됨(승객을 태우는 시점에 cur fuel 저장)
    if (!ride(personIndex))
      return -1;
    personNum--;
    if (personNum == 0) {
      return start_fuel;
    }
  }
}

int main() {
  In();
  int result = findAns();
  printf("%d\n", result);

  return 0;
}
