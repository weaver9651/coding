#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

// stoi(string), to_string(int)

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
  return true;
}

int findScore(int num) {
  string s = to_string(num);
  int score = 0;
  for (int i = 0; i < s.size(); i++) {
    string cpy = s;
    cpy.erase(i, 1);
    int tmp_num = stoi(cpy);
    if (isPrime(tmp_num))
      score++;
  }
  return score;
}

int main () {
  int A;
  scanf("%d", &A);
  int scoreA = findScore(A);

  return 0;
}
