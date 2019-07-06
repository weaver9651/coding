#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int N;
int rightadd[5000];
int leftadd[5000];

int *flipArr(int *arr, int start, int end) {
  int *result = new int[N];
  copy(arr, arr+N, result);
  for (int i = 0; i <= end-start; i++) {
    result[start+i] = arr[end-i];
  }

  return result;
}

int getPoint(int *arrA, int *arrB, int maxx) {
  int counter = 0;
  for (int i = 0; i < N; i++) {
    if (counter+N-i < maxx)
      break;
    if (arrA[i] == arrB[i])
      counter++;
  }
  return counter;
}

int getPoint2(int *arrA, int *arrB, int start, int end) {
  int cur = 0;
  int next = 0;
  int result = 0;
  for (int i = 0; i <= end-start; i++) {
    if (arrA[start+i] == arrB[start+i])
      cur++;
    if (arrA[start+i] == arrB[end-i])
      next++;
  }
  if (start != 0) {
    result += rightadd[start-1];
  }
  if (end != N-1) {
    result += leftadd[end+1];
  }
  result += next;
  return result;
}

int findAnswer(int *arrA, int *arrB) {
  int maxx = leftadd[0];
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      int cur_score = 0;
      cur_score = getPoint2(arrA, arrB, i, j);
      if (cur_score > maxx) {
	maxx = cur_score;
      }
    }
  }
  return maxx;
}

void accumulate(int *arrA, int *arrB) {
  int counterright = 0;
  int counterleft = 0;
  for (int i = 0; i < N; i++) {
    if (arrA[i] == arrB[i]) {
      counterright++;
    }
    rightadd[i] = counterright;      
    if (arrA[N-i-1] == arrB[N-i-1]) {
      counterleft++;
    }
    leftadd[N-i-1] = counterleft;
  }
}

int main () {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    scanf("%d", &N);
    int *arrA = new int[N];
    int *arrB = new int[N];
    for (int i = 0; i < N; i++) {
      scanf("%d", &arrA[i]);    
    }
    for (int i = 0; i < N; i++) {
      scanf("%d", &arrB[i]);
    }

    accumulate(arrA, arrB); 

    int result = findAnswer(arrA, arrB);
    printf("Case #%d\n%d\n", tc, result);
    delete [] arrA;
    delete [] arrB;
  }

  // // debug
  // for (int i = 0; i < N; i++) {
  //   printf("%d ", resultA[i]);
  // }
  // cout << endl;
  
  return 0;
}
