#include <iostream>
#include <map>
#include <queue>
#include <deque>

using namespace std;

int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void In(char **Map, vector<char> &keys, int N, int M) {
  char tmp;
  for (int i = 0; i < M + 2; i++) {
    Map[0][i] = '.';
  }
  scanf("%c", &tmp);
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M + 2; j++) {
      if (j == 0 || j == M + 1) {
	Map[i][j] = '.';
      }
      else {
	scanf("%c", &Map[i][j]);
      }
    }
    scanf("%c", &tmp);
  }
  for (int i = 0; i < M + 2; i++) {
    Map[N + 1][i] = '.';
  }
  while (true) {
    scanf("%c", &tmp);
    if (tmp == 0 || tmp == '\n') break;
    keys.push_back(tmp);
  }
}

bool isKey(vector<char> keys, char x) {
  int counter = 0;
  for (char i : keys) {
    if (i == x) counter++;
  }
  if (counter)
    return true;
  return false;
}

int bfs(char **Map, vector<char> &keys, multimap<char, pair<int, int> > &doors,
	int N, int M) {
  int counter = 0;
  bool visit[102][102] = {false, };
  deque<pair<int, int> > q;
  q.push_back(make_pair(0, 0));
  int cur_y, cur_x, tmp_y, tmp_x;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop_front();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (tmp_y >= 0 && tmp_y < N + 2 && tmp_x >= 0 && tmp_x < M + 2 &&
	  !visit[tmp_y][tmp_x] && Map[tmp_y][tmp_x] != '*') {

	// if door
	if (Map[tmp_y][tmp_x] >= 'A' && Map[tmp_y][tmp_x] <= 'Z') {
	  // if the key exists
	  if (isKey(keys, Map[tmp_y][tmp_x] + 32)) {
	    visit[tmp_y][tmp_x] = true;
	    q.push_back(make_pair(tmp_y, tmp_x));
	  }
	  // if the key does not exist
	  else {
	    visit[tmp_y][tmp_x] = true;
	    doors.insert(make_pair(Map[tmp_y][tmp_x], make_pair(tmp_y, tmp_x)));
	  }
	}
	// if key
	else if (Map[tmp_y][tmp_x] >= 'a' && Map[tmp_y][tmp_x] <= 'z') {
	  // if doors exist
	  if (doors.find(Map[tmp_y][tmp_x] - 32) != doors.end()) {
	    visit[tmp_y][tmp_x] = true;
	    q.push_back(make_pair(tmp_y, tmp_x));
	    keys.push_back(Map[tmp_y][tmp_x]);
	    for (multimap<char, pair<int, int> >::iterator iter = doors.equal_range(Map[tmp_y][tmp_x] - 32).first;
		 iter != doors.equal_range(Map[tmp_y][tmp_x] - 32).second;
		 iter++) {
	      visit[iter->second.first][iter->second.second] = true;
	      q.push_front(make_pair(iter->second.first, iter->second.second));
	    }
	  }
	  // if doors do not exist
	  else {
	    visit[tmp_y][tmp_x] = true;
	    keys.push_back(Map[tmp_y][tmp_x]);
	    q.push_back(make_pair(tmp_y, tmp_x));
	  }
	}
	// if not door and not key
	else {
	  visit[tmp_y][tmp_x] = true;
	  q.push_back(make_pair(tmp_y, tmp_x));
	  // if '$'
	  if (Map[tmp_y][tmp_x] == '$') {
	    counter++;
	  }
	}
      }
    }
  }

  return counter;
}

int main() {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    int N, M;
    cin >> N >> M;
    char **Map;
    Map = new char*[N+2];
    for (int i = 0; i < N + 2; i++) {
      Map[i] = new char[M + 2];
    }
    vector<char> keys;
    multimap<char, pair<int, int> > doors;
    In(Map, keys, N, M);
    cout << bfs(Map, keys, doors, N, M) << endl;
  }

  return 0;
}
