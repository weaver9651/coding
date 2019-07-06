#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// stoi(string), to_string(int)

int maxx = 0;

bool isPrime(int num) {
  if (num == 1) return false;
  if (num == 2) return true;

  int range = sqrt(num);
  int *arr = new int[range+1];
  for (int i = 2; i <= range; i++) {
    arr[i] = 1;
  }
  /*----preprocessing----*/
  for (int i = 2; i <= range; i++) {
    if (arr[i] == 0)
      continue;
    
    else {
      if (num % i == 0) {
  	return false;
      }
      else {
  	for (int j = i; j <= range; j+=i) {
  	  arr[j] = 0;
  	}
      }	
    }
  }

  // // naive version
  // for (int i = 2; i <= range; i++) {
  //   if ((num % i) == 0)
  //     return false;
  // }
  return true;
}

void findScore(string s, int score) {
  if (isPrime(stoi(s)))
    score++;
  if (s.size() == 1) {
    maxx = max(maxx, score);
    return;
  }

  for (int i = 0; i < s.size(); i ++) {
    string cpy = s;
    cpy.erase(i, 1);
    findScore(cpy, score);
  }
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    int A, B, scoreA, scoreB;
    scanf("%d%d", &A, &B);
    if (isPrime(A)) {
      findScore(to_string(A), 0);
      scoreA = maxx;
      maxx = 0;
    }
    else {
      scoreA = 0;
    }
    if (isPrime(B)) {
      findScore(to_string(B), 0);
      scoreB = maxx;
      maxx = 0;
    }
    else {
      scoreB = 0;
    }
    // cout << scoreA << " " << scoreB << endl;
    printf("Case #%d\n", tc);
    scoreA > scoreB ? printf("%d\n", 1) : scoreA < scoreB ? printf("%d\n", 2) : printf("%d\n", 3);
  }

  // // test
  // int A;
  // scanf("%d", &A);
  // findScore(to_string(A), 0);
  // int scoreA = maxx;
  // maxx = 0;
  // cout << scoreA << endl;

  return 0;
}
