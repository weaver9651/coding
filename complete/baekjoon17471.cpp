#include <bits/stdc++.h>
using namespace std;

int minn = 1000;
int N;
int people[11];
bool Map[11][11] = {false,};

void In() {
  // the number of people in each node
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    scanf("%d", &people[i]);

  // whether two nodes are connected
  int tmp;
  for (int i = 1; i <= N; i++) {
    int num;
    scanf("%d", &num);
    for (int j = 0; j < num; j++) {
      scanf("%d", &tmp);
      Map[i][tmp] = true;
    }
  }
  
}

bool isIn(int value, vector<int> team) {
  for (vector<int>::iterator it = team.begin(); it != team.end(); it++) {
    if (*it == value)
      return true;
  }
  return false;
}

bool bfs(vector<int> team) {
  int cur, tmp;
  queue<int> q;
  vector<bool> visit(N+1, false);

  cur = team.back();
  team.pop_back();
  q.push(cur);
  visit[cur] = true;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    for (int i = 1; i <= N; i++) {
      if (!visit[i] && isIn(i, team) && Map[cur][i]) {
	q.push(i);
	visit[i] = true;
      }
    }
  }

  bool result = true;
  for (vector<int>::iterator it = team.begin(); it != team.end(); it++) {
    result &= visit[*it];
  }
  return result;
}

bool isValid(vector<int> teamA, vector<int> teamB) {
  bool result = true;
  result &= bfs(teamA);
  result &= bfs(teamB);
  return result;
}

void calc(int teambit) {
  vector<int> teamA;
  vector<int> teamB;
  for (int i = 1; i <= N; i++) {
    if (1 & (teambit >> i))
      teamA.push_back(i);
    else
      teamB.push_back(i);
  }

  if (teamA.empty() || teamB.empty())
    return;

  /* for debugging */
  // for (vector<int>::iterator it = teamA.begin(); it != teamA.end(); it++)
  //   printf("%d ", *it);
  // printf("\n");

  // for (vector<int>::iterator it = teamB.begin(); it != teamB.end(); it++)
  //   printf("%d ", *it);
  // printf("\n");
  // printf("\n");

  // check all nodes are connected
  if (!isValid(teamA, teamB))
    return;

  int numA = 0, numB = 0;
  for (vector<int>::iterator it = teamA.begin(); it != teamA.end(); it++) {
    numA += people[*it];
  }
  for (vector<int>::iterator it = teamB.begin(); it != teamB.end(); it++) {
    numB += people[*it];
  }
  minn = min(minn, abs(numA-numB));
}

void makeTeam(int select_cnt, int index, int teambit) {
  // teambit does not use the LSB;
  if (index > N) {
    calc(teambit);
    return;
  }

  // avoid same cases
  if (select_cnt > N/2)
    return;
  
  makeTeam(select_cnt, index+1, teambit);
  makeTeam(select_cnt+1, index+1, teambit | (1 << index));
}

void findAns() {
  if (N <= 1)
    return;
  makeTeam(0, 1, 0);
}

int main () {
  In();
  findAns();
  printf("%d\n", minn == 1000 ? -1 : minn);
  
  return 0;
}
