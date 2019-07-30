#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
최소 1개 모음, 2개 자음
C : 문자 종류
L : 암호 자릿수
오름차순으로만 정렬
*/

int L, C;
vector<char> chars;

void In() {
  scanf("%d%d", &L, &C);
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < C; i++) {
    scanf("%c", &tmp);
    chars.push_back(tmp);
    scanf("%c", &tmp); // remove newline
  }
}

bool isOK(string word) {
  int vowel = 0;
  int consonant = 0;
  for (int i = 0; i < word.size(); i++) {
    if (word[i] == 'a' ||
	word[i] == 'e' ||
	word[i] == 'i' ||
	word[i] == 'o' ||
	word[i] == 'u' ) {
      vowel++;
    }
    else
      consonant++;
  }
  if (vowel >= 1 && consonant >= 2)
    return true;
  else
    return false;
}

void dfs(int index, string word, int length) {
  if (length == L) {
    if (isOK(word)) {
      cout << word << endl;
    }
    return;
  }
  if (index >=  C)
    return;
  dfs(index+1, word.append(1, chars[index]), length+1);
  word = word.substr(0, word.size()-1);
  dfs(index+1, word, length);
}

int main () {
  In();
  sort(chars.begin(), chars.end());
  string word = "";
  dfs(0, word, 0);
  
  // for (vector<char>::iterator it = chars.begin(); it != chars.end(); it++) {
  //   printf("%c ", *it);
  // }
  
  return 0;
}
