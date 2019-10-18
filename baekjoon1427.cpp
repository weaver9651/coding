#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void merge(int start, int end, string &num) {
  string newnum = "";
  int mid = (start + end ) / 2;
  int i = start;
  int j = mid + 1;
  while (i <= mid && j <= end) {
    if (num[i] >= num[j]) {
      newnum +=num[i];
      i++;
    }
    else {
      newnum +=num[j];
      j++;
    }
  }
  while (i <= mid) {
    newnum += num[i];
    i++;
  }
  while (j <= end) {
    newnum += num[j];
    j++;
  }
  for (int i = start; i <= end; i++) {
    num[i] = newnum[i-start];
  }
}

void mergeSort(int start, int end, string &num) {
  if (start == end)
 return;
  int mid = (start + end) / 2;
  mergeSort(start, mid, num);
  mergeSort(mid+1, end, num);
  merge(start, end, num);
}

string mySort(string num) {
  int start = 0;
  int end = num.size() - 1;
  mergeSort(start, end, num);
  return num;
}

int main () {
  string num;
  cin >> num;
  num = mySort(num);
  cout << num << endl;
  
  return 0;
}
