#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

bool visit[10000] = {false,};
bool isPrime[10000] = {false,};
int dist[10000] = {0,};
int src, dst;

void findPrime() {
  for (int i = 1001; i <= 9999; i++) {
    int counter = 0;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0)
	counter++;
    }
    if (counter)
      isPrime[i] = false;
    else
      isPrime[i] = true;
  }
}

void In() {
  scanf("%d%d", &src, &dst);
}

void init() {
  for (int i = 1001; i <= 9999; i++) {
    visit[i] = false;
    dist[i] = 0;
  }
}

vector<int> nearPrime(int num) {
  vector<int> primes;
  // 1000
  string numstring = to_string(num);
  int tmp;
  for (int i = 0; i <= 9; i++) {
    numstring[0] = i + '0';
    tmp = stoi(numstring);
    if (isPrime[tmp])
      primes.push_back(tmp);
  }
  
  numstring = to_string(num);
  for (int i = 0; i <= 9; i++) {
    numstring[1] = i + '0';
    tmp = stoi(numstring);
    if (isPrime[tmp])
      primes.push_back(tmp);
  }

  numstring = to_string(num);
  for (int i = 0; i <= 9; i++) {
    numstring[2] = i + '0';
    tmp = stoi(numstring);
    if (isPrime[tmp])
      primes.push_back(tmp);
  }
  
  numstring = to_string(num);
  for (int i = 0; i <= 9; i++) {
    numstring[3] = i + '0';
    tmp = stoi(numstring);
    if (isPrime[tmp])
      primes.push_back(tmp);
  }
  
  return primes;
}
int bfs() {
  int cur, tmp;
  queue<int> q;
  q.push(src);
  visit[src] = true;
  dist[src] = 0;
  if (src == dst)
    return 0;

  while (!q.empty()) {
    cur = q.front();
    q.pop();

    vector<int> primes;
    primes = nearPrime(cur);
    for (auto x : primes) {
      if (visit[x])
	continue;
      visit[x] = true;
      dist[x] = dist[cur] + 1;
      if (x == dst)
	return dist[x];
      q.push(x);
    }
  }
  return -1;
}

int main () {
  findPrime();

  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    init();
    In();
    int result = bfs();
    if (result == -1)
      printf("Impossible\n");
    else
      printf("%d\n", result);
  }
  
  return 0;
}
