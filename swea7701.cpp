#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 50

using namespace std;

int main () {
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    int N;
    cin >> N;
    vector<string> *ptr = new vector<string>[MAX + 1];

    char dummy;
    scanf("%c", &dummy);
    string tmp;
    for (int i = 0; i < N; i++) {
      char *a = new char[MAX+2];
      fgets(a, sizeof(char)*(MAX+2), stdin);
      a[strlen(a)-1] = NULL;
      tmp = string(a);
      ptr[tmp.size()].push_back(tmp);
    }

    printf("#%d\n", tc);
    for (int i = 1; i <= MAX; i++) {
      if (!ptr[i].empty()) {
	sort(ptr[i].begin(), ptr[i].end());
	ptr[i].erase(unique(ptr[i].begin(), ptr[i].end()), ptr[i].end());
	for (vector<string>::iterator iter = ptr[i].begin(); iter != ptr[i].end(); iter++) {
	  cout << *iter << endl;
	}
      }
    }
  }
  
  return 0;
}
