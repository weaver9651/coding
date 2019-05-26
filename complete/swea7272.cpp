#include <iostream>
#include <string>

using namespace std;

char ctoc(char before) {
  if (before == 'B') {
    return '2';
  }
  else if (before == 'A' || before == 'D' ||
	   before == 'O' || before == 'P' ||
	   before == 'Q' || before == 'R') {
    return '1';
  }
  else {
    return '0';
  }
}

string ston(string before) {
  string after;
  for (int i = 0; i < before.size(); i++) {
    after.append(1, ctoc(before[i]));
  }
  return after;
}

int main () {
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    string a, b;
    cin >> a >> b;
    a = ston(a);
    b = ston(b);
  
    string ans;
  
    if (a == b)
      ans = "SAME";
    else
      ans = "DIFF";

    cout << "#" << tc+1 << " " << ans << endl;
  }
  
  return 0;
}
