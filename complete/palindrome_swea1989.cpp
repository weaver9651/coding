#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    string word;
    int flag = 1;
    cin >> word;
    for (int i = 0; i < word.length() / 2; i++) {
      int j = word.length() - i - 1;
      if (word[i] != word[j]) {
	flag = 0;
	break;
      }
    }
    printf("#%d %d\n", tc+1, flag);
  }
  
  return 0;
}
