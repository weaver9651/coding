#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main () {
  int T;
  char tmp;
  scanf("%d", &T);
  scanf("%c", &tmp);

  for (int tc = 1; tc <= T; tc++) {
    char buf[10];
    fgets(buf, sizeof(char)*10, stdin);
    string time1 = (string)buf;
    fgets(buf, sizeof(char)*10, stdin);
    string time2 = (string)buf;
  
    time1[time1.size() - 1] = NULL;
    time2[time2.size() - 1] = NULL;
  
    int h1 = atoi(time1.substr(0, 2).c_str());
    int m1 = atoi(time1.substr(3, 5).c_str());
    int s1 = atoi(time1.substr(6, 8).c_str());

    int h2 = atoi(time2.substr(0, 2).c_str());
    int m2 = atoi(time2.substr(3, 5).c_str());
    int s2 = atoi(time2.substr(6, 8).c_str());

    int carry1, carry2;
    int h, m, s;

    if (s2-s1 < 0) {
      carry1 = 1;
      s = s2-s1 + 60;
    }
    else {
      carry1 = 0;
      s = s2-s1;
    }

    if (m2-m1-carry1 < 0) {
      carry2 = 1;
      m = m2-m1-carry1 + 60;
    }
    else {
      carry2 = 0;
      m = m2-m1-carry1;
    }

    if (h2-h1-carry2 < 0) {
      h = h2-h1-carry2 + 24;
    }
    else {
      h = h2-h1-carry2;
    }

    printf("#%d %02d:%02d:%02d\n", tc, h, m, s);
  }
  
  return 0;
}
