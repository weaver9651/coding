#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
Codes causing timeout commented out.
*/

int Map[20][20];
int dist[20][20] = {0,};
int shark_y, shark_x;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
// bool visit[20][20] = {false, };
int level = 2;
int exp = 0;
int N;

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

void In() {
  scanf("%d", &N);
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &tmp);
      Map[i][j] = tmp;
      if (tmp == 9) {
	shark_y = i;
	shark_x = j;
	Map[i][j] = 0;
      }
    }
  }
}

bool bfs(int start_y, int start_x) {
  bool visit[20][20] = {false, };
  int cur_y, cur_x;
  int tmp_y, tmp_x;
  queue<pair<int, int> > q;
  queue<pair<int, int> > buffer;
  vector<pair<int, int> > candidates;
  q.push(make_pair(start_y, start_x));
  visit[start_y][start_x] = true;
  
  while (!q.empty() || !buffer.empty()) {
    if (!candidates.empty()) {
      int minny = 1000;
      int minnx = 1000;
      int index = 0;
      int counter = 0;
      for (vector<pair<int, int> >::iterator it = candidates.begin();
	   it != candidates.end(); it++) {
	counter++;
	if (it->first < minny) {
	  minny = it->first;
	  minnx = it->second;
	  index = counter;
	}
	else if (it->first == minny) {
	  if (it->second < minnx) {
	    minnx = it->second;
	    index = counter;
	  }
	}
      }
      tmp_y = candidates[index-1].first;
      tmp_x = candidates[index-1].second;
      int tmp = Map[tmp_y][tmp_x];
      Map[tmp_y][tmp_x] = 0;
      exp++;
      if (exp >= level) {
	exp = 0;
	level++;
      }
      shark_y = tmp_y;
      shark_x = tmp_x;
      return true;
    }

    while (!buffer.empty()) {
      q.push(buffer.front());
      buffer.pop();
    }

    while (!q.empty()) {        
      cur_y = q.front().first;
      cur_x = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
	tmp_y = cur_y + dy[i];
	tmp_x = cur_x + dx[i];
	if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] <= level && !visit[tmp_y][tmp_x]) {
	  visit[tmp_y][tmp_x] = true;
	  buffer.push(make_pair(tmp_y, tmp_x));
	  dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	  if (Map[tmp_y][tmp_x] < level && Map[tmp_y][tmp_x] > 0) {
	    candidates.push_back(make_pair(tmp_y, tmp_x));
	  }
	}
      }
    }
  } // while q buffer end
  return false;
}

// void init() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       visit[i][j] = false;
//     }
//   }
// }

// bool isFood() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       if (Map[i][j] < level && Map[i][j] > 0)
// 	return true;
//     }
//   }
//   return false;
// }

void Out() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d ", Map[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int findAns() {
  while(bfs(shark_y, shark_x)) {
    //    bfs(shark_y, shark_x);
    //    Out();
    //    init();
    /* do nothing */;
  }
  return dist[shark_y][shark_x];
}

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
