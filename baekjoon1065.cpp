#include <cstdio>
#include <string>

using namespace std;

int findAns(int N) {
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (i / 100 == 0) {
      count++;
      continue;
    }
    else {
      string s = to_string(i);
      int size = s.size();
      int oldd = -100, newd = -100;
      bool flag = true;
      for (int j = 0; j < size - 1; j++) {
	oldd = newd;
	newd = s[j+1] - s[j];
	if (oldd == -100)
	  continue;
	if (oldd != newd)
	  flag = false;
      }
      if (flag)
	count++;
    }
  } //for end
  return count;
}

int main () {
  int N;
  scanf("%d", &N);
  int result = findAns(N);
  printf("%d\n", result);
  
  return 0;
}
