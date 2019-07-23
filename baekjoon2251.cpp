#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[201][201][201] = {false, };
vector<int> results;

pair<int, pair<int, int> > make_tri(int a, int b, int c) {
  return make_pair(a, make_pair(b, c));
}

bool pour(int A, int B, int C, int &cur_a, int &cur_b, int &cur_c, int flag) {
  int dlddu;
  switch (flag) {
  case 0:
    // a to b
    dlddu = B - cur_b;
    if (dlddu == 0 || cur_a == 0)
      return false;
    if (dlddu >= cur_a) {
      cur_b += cur_a;
      cur_a = 0;
    }
    else {
      cur_b += dlddu;
      cur_a -= dlddu;
    }
    return true;
  case 1:
    // b to c
    dlddu = C - cur_c;
    if (dlddu == 0 || cur_b == 0)
      return false;
    if (dlddu >= cur_b) {
      cur_c += cur_b;
      cur_b = 0;
    }
    else {
      cur_c += dlddu;
      cur_b -= dlddu;
    }
    return true;
  case 2:
    // c to a
    dlddu = A - cur_a;
    if (dlddu == 0 || cur_c == 0)
      return false;
    if (dlddu >= cur_c) {
      cur_a += cur_c;
      cur_c = 0;
    }
    else {
      cur_a += dlddu;
      cur_c -= dlddu;
    }
    return true;
  case 3:
    // a to c
    dlddu = C - cur_c;
    if (dlddu == 0 || cur_a == 0)
      return false;
    if (dlddu >= cur_a) {
      cur_c += cur_a;
      cur_a = 0;
    }
    else {
      cur_c += dlddu;
      cur_a -= dlddu;
    }
    return true;
  case 4:
    // c to b
    dlddu = B - cur_b;
    if (dlddu == 0 || cur_c == 0)
      return false;
    if (dlddu >= cur_c) {
      cur_b += cur_c;
      cur_c = 0;
    }
    else {
      cur_b += dlddu;
      cur_c -= dlddu;
    }
    return true;
  case 5:
    // b to a
    dlddu = A - cur_a;
    if (dlddu == 0 || cur_b == 0)
      return false;
    if (dlddu >= cur_b) {
      cur_a += cur_b;
      cur_b = 0;
    }
    else {
      cur_a += dlddu;
      cur_b -= dlddu;
    }
    return true;
  }
}

void bfs(int A, int B, int C) {
  int cur_a = 0, cur_b = 0, cur_c = C;
  visit[cur_a][cur_b][cur_c] = true;
  results.push_back(cur_c);
  vector<pair<int, pair<int, int> > > s;
  s.push_back(make_tri(cur_a, cur_b, cur_c));

  while (!s.empty()) {
    cur_a = s.back().first;
    cur_b = s.back().second.first;
    cur_c = s.back().second.second;
    s.pop_back();

    int tmp_a, tmp_b, tmp_c;
    for (int i = 0; i < 6; i++) {
      tmp_a = cur_a, tmp_b = cur_b, tmp_c = cur_c;
      bool flag = pour(A, B, C, tmp_a, tmp_b, tmp_c, i);
      if (!flag)
	continue;
      if (!visit[tmp_a][tmp_b][tmp_c]) {
	visit[tmp_a][tmp_b][tmp_c] = true;
        s.push_back(make_tri(tmp_a, tmp_b, tmp_c));
	if (tmp_a == 0)
	  results.push_back(tmp_c);
      }
    }
  }
  
}

int main () {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);

  bfs(A, B, C);
  sort(results.begin(), results.end());
  results.erase(unique(results.begin(), results.end()), results.end());
  for (vector<int>::iterator it = results.begin(); it != results.end(); it++) {
    printf("%d ", *it);
  }
  printf("\n");
  
  
  return 0;
}
