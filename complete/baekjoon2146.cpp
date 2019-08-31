#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

/*
1. 대륙마다 색칠
 1-1. 색칠하면서 해당 영역이 바다랑 닿아있으면 경계로 지정(vector<vector<pair<int,int> > >)

2. 대륙마다 경계를 돌면서 다른 대륙을 만나는 가장 짧은 거리를 출력
 2-1. 
*/

vector<vector<pair<int,int> > > lands;
int N;
int Map[100][100] = {0,};
bool visit[100][100] = {false,};
int colorMap[100][100] = {0,};
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
void Out();
void In() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      scanf("%d", &Map[i][j]);
    }
}

bool isInside(int y, int x) {
  if (y >= 0 && y < N && x >= 0 && x < N)
    return true;
  else
    return false;
}

bool isBorder(int y, int x) {
  bool flag = false;
  int tmp_y, tmp_x;
  for (int i = 0; i < 4; i++) {
    tmp_y = y + dy[i];
    tmp_x = x + dx[i];
    if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 0 && Map[y][x] == 1)
      flag = true;
  }
  return flag;
}

void bfs(int y, int x, int color) {
  // Only for coloring a land with a different color compared to others
  int cur_y, cur_x, tmp_y, tmp_x;
  queue<pair<int,int> > q;
  vector<pair<int,int> > border;
  q.push(make_pair(y, x));
  visit[y][x] = true;
  colorMap[y][x] = color;
  if (isBorder(y, x))
    border.push_back(make_pair(y, x));

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && Map[tmp_y][tmp_x] == 1 && !visit[tmp_y][tmp_x]) {
	if (isBorder(tmp_y, tmp_x))
	  border.push_back(make_pair(tmp_y, tmp_x));
	visit[tmp_y][tmp_x] = true;
	colorMap[tmp_y][tmp_x] = color;
	q.push(make_pair(tmp_y, tmp_x));
      }
    }
  }
  if (!border.empty())
    lands.push_back(border);
}

int shortestBridge(int y, int x) {
/*
현 위치는 dist = 0;
바다로 이동
육지인데 같은 색이면 가지 않음
육지인데 다른 색이면 해당 cell까지 count하고 return count-1;
*/
  int cur_color = colorMap[y][x];
  int cur_y, cur_x, tmp_y, tmp_x;
  int dist[100][100] = {0,};
  bool visit2[100][100] = {false,};
  queue<pair<int,int> > q;
  q.push(make_pair(y, x));
  visit2[y][x] = true;
  dist[y][x] = 0;

  while (!q.empty()) {
    cur_y = q.front().first;
    cur_x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      tmp_y = cur_y + dy[i];
      tmp_x = cur_x + dx[i];
      if (isInside(tmp_y, tmp_x) && !visit2[tmp_y][tmp_x]) {
	// valid cell
	if (Map[tmp_y][tmp_x] == 1) { // land
	  if  (colorMap[tmp_y][tmp_x] == cur_color)
	    continue;
	  else { // different color
	    return dist[cur_y][cur_x];
	  }
	}
	else { // sea
	  visit2[tmp_y][tmp_x] = true;
	  dist[tmp_y][tmp_x] = dist[cur_y][cur_x] + 1;
	  q.push(make_pair(tmp_y, tmp_x));
	}
      } // end if valid test
    } // end for
  }
  return 200;
}

int findAns() {
  int color_cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visit[i][j] && Map[i][j] == 1) {
	color_cnt++;
	bfs(i, j, color_cnt);
      }
    }
  }
  //  Out();
  int cur_y, cur_x;
  int minn = 200;
  int cur_min;
  while(!lands.empty()) {
    vector<pair<int,int> > land = lands.back();
    lands.pop_back();
    for (vector<pair<int,int> >::iterator it = land.begin();
	 it != land.end(); it++) {
      cur_y = it->first;
      cur_x = it->second;
      cur_min = shortestBridge(cur_y, cur_x);
      minn = min(minn, cur_min);
    }
  }
  return minn;
}

// void Out() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       printf("%d ", colorMap[i][j]);
//     }
//     printf("\n");
//   }
// }

int main () {
  In();
  int result = findAns();
  printf("%d\n", result);
  
  return 0;
}
