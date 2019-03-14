#include <iostream>

using namespace std;

int rowInit(int n) {
  int result = (n*n - n + 2) / 2;
  return result;
}

int findInit(int num) {
  int counter = 1;
  while(rowInit(counter) < num) {
    counter++;
  }

  return counter - 2;  
}

void findCell(int num) {
  
}

int main () {

  
  
  
  return 0;
}
