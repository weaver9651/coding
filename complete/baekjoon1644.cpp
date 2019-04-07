#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void findPrime(int N, vector<int> &prime) {
  for (int i = 2; i <= N; i++) {
    int root = sqrt(i);
    int counter = 0;
    for (int j = 2; j <= root; j++) {
      int remain = i % j;
      if (remain == 0) break;
      counter++;
    }
    if (counter == root - 1) {
      prime.push_back(i);
    }
  }
}

int findCase(int N, vector<int> &prime) {
  if (N == 1) return 0;
  if (N == 2 || N == 3) return 1;

  int now = *prime.begin();
  int counter = 0;
  for (vector<int>::iterator i = prime.begin(), j = prime.begin();
       i != prime.end(); i++) {
    while (j != prime.end()) {
      if (now == N) {
	counter++;
	j++;
	if (j == prime.end()) break;
	now += *j;
	continue;
      }
      else if (now < N) {
	j++;
	if (j == prime.end()) break;
	now += *j;
	continue;
      }
      else if (now > N) {
	now -= *i;
	break;
      }
    }
    if (j == prime.end()) {
      if (i + 1 == prime.end())
	return counter;
      if (now > N) {
	now -= *i;
	continue;
      }
      else if (now == N) {
	counter++;
	now -= *i;
	continue;
      }
      else /* now < N */ {
	return counter;
      }
    }
  }
  return counter;
}

// 1, 2, 3은 따로 처리
int main() {
  int N;
  cin >> N;
  vector<int> prime;
  findPrime(N, prime);

  //// findPrime function debugging
  //if (!prime.empty())
  //    for (int x : prime) {
  //        cout << x << " ";
  //    }
  //    cout << endl;

  cout << findCase(N, prime) << endl;

  return 0;
}
