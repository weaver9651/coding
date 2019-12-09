#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string partial(string p) {
  int numLeft = 0;
  int numRight = 0;
  int index;
  for (int i = 0; i < p.size(); i++) {
    if (p[i] == '(')
      numLeft++;
    else
      numRight++;
    if (numLeft == numRight) {
      index = i;
      break;
    }
  }
  char arr[1010];
  cout << index << endl;
  p.copy(arr, index+1);
  string u(arr);
  cout << u << endl;

  memset(arr, '\0', 1010);
  p.copy(arr, index, index+1);
  string v(arr);
  cout << v << endl;
  
}

string solution(string p) {
  string answer = "";
  if (p.size() == 0)
    return answer;

  
  return answer;
}

int main () {
  solution("(()())()");
  
  return 0;
}
