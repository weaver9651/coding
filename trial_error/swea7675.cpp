#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string trim(string word) {
  int pos;
  if (word.find(".") != string::npos) {
    pos = word.find(".");
    word = word.substr(0, pos);
  }

  return word;
}

string dot(string word) {
  int pos;
  if (word.find("!") != string::npos) {
    pos = word.find("!");
    word[pos] = '.';
  }
  else if (word.find(".") != string::npos) {
    pos = word.find(".");
    word[pos] = '.';
  }
  else if (word.find("?") != string::npos) {
    pos = word.find("?");
    word[pos] = '.';
  }
  word[word.size()-2] = '.';

  return word;
}

vector<string> split(string s, string delim) {
  vector<string> words;
  int pos = 0;
  string token;
  // if not found, return npos
  while ((pos = s.find(delim)) != string::npos) {
    token = s.substr(0, pos); // split
    token = trim(token);
    words.push_back(token);
    s.erase(0, pos + delim.length()); // erease splited token
  }
  s = trim(s);
  words.push_back(s);

  return words;
}

bool isName(string word) {
  bool flag1 = true;
  bool flag2 = true;
  for (int i = 0; i < word.size(); i++) {
    if (i == 0) {
      if (!(word[i] >= 'A' && word[i] <= 'Z'))
	flag1 = false;
    }
    else {
      if (!(word[i] >= 'a' && word[i] <= 'z'))
	flag2 = false;      
    }
  }

  return flag1 & flag2;
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    printf("#%d\n", tc);
    int N;
    scanf("%d", &N);
    char tmp;
    scanf("%c", &tmp);
    char buf[1001];
    fgets(buf, 1001, stdin);
    string s = (string)buf;
    //    s[s.size()-1] = NULL;

    vector<string> sentences;
    s = dot(s);
    sentences = split(s, ". ");

    for (int i = 0; i < N; i++) {
      vector<string> words;
      words = split(sentences[i], " ");
      int result = 0;
      for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
	if (isName(*iter))
	  result++;
      }
      printf("%d ", result);
    }
    printf("\n");
  }
  
  return 0;
}
