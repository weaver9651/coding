#include <bits/stdc++.h>
using namespace std;

long long findAns () {
  vector<long> s;
  int N;
  scanf("%d", &N);
  char *arr = new char[N];
  char ch;
  scanf("%c", &ch); // remove newline
  for (int i = 0; i < N; i++) {
    scanf("%c", &ch);
    arr[i] = ch;
  }
  int num, num1, num2;
  for (int i = 0; i < N; /* do nothing */) {
    ch = arr[i];
    i++;
    if (ch == '(') {
      s.push_back(-1);
    }
    else if (ch == '*') {
      ch = arr[i];
      i++;
      if (ch == '(') {
	s.push_back(-2);
	ch = arr[i];
	i++;
	goto START2;
      }
      num = ch - '0';
      num1 = s.back();
      s.pop_back();
      num = num * num1;
      s.push_back(num);
    }
    else if (ch == '+') {
    START:
      ch = arr[i];
      i++;
      if (ch == '(') {
        s.push_back(-1);
	goto START;
      }
      num = ch - '0';
      s.push_back(num);
    }
    else if (ch >= '0' && ch <= '9') {
    START2:
      num = ch - '0';
      s.push_back(num);
    }
    else if (ch == ')') {
      num = 0;
      while (s.back() >= 0) {
	num += s.back();
	s.pop_back();
      }
      if (s.back() == -1) {
	s.pop_back();
	s.push_back(num);
      }
      else {
	s.pop_back();
	s.back() *= num;
      }
    }
  }

  long long result = 0;;
  while (!s.empty()) {
    result += s.back();
    s.pop_back();
  }
  
  return result;
}

int main () {
  for (int tc = 1; tc <= 10; tc++) {
    long long result = findAns();
    printf("#%d %lld\n", tc, result);
  }
}
