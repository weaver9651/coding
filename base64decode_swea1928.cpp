#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char base64table[64];

void init() {
  for (int i = 0; i < 26; i++) {
    base64table[i] = 'A' + i;
  }
  for (int i = 0; i < 26; i++) {
    base64table[i + 26] = 'a' + i;
  }
  for (int i = 0; i < 10; i++) {
    base64table[i + 52] = '0' + i;
  }
  base64table[62] = '+';
  base64table[63] = '/';
  
}

int basetochar(char x) {
  for (int i = 0; i < 64; i++) {
    if (base64table[i] == x)
      return i;
  }
}

void decoder(string s) {
  int buffer[4];
  char buffer2[3];
  int base = 0;
  
  while (base != s.length()) {
    for (int i = 0; i < 4; i++) {
      buffer[i] = basetochar(s[i+base]);
    }
    base += 4;

    // clear buffer2
    for (int i = 0; i < 3; i++) {
      buffer2[i] = 0;
    }

    buffer2[2] |= buffer[3];
    buffer2[2] |= (buffer[2] & 0b11) << 6;
    buffer2[1] |= (buffer[2] >> 2);
    buffer2[1] |= (buffer[1] & 0b1111) << 4;
    buffer2[0] |= (buffer[1] >> 4);
    buffer2[0] |= buffer[0] << 2;

    for (int i = 0; i < 3; i++) {
      printf("%c", buffer2[i]);
    }
  }
  cout << "\n";
}

int main () {
  init();
  int T;
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    string s;
    cin >> s;
    decoder(s);
  }
  
  return 0;
}
