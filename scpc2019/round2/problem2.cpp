#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int N;

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

bool isPlus(int *arrA, int *arrB, int start, int end) {
  int cur = 0;
  int next = 0;
  for (int i = 0; i <= end-start; i++) {
    if (arrA[start+i] == arrB[start+i])
      cur++;
    if (arrA[start+i] == arrB[end-i])
      next++;
  }
  if (next > cur)
    return true;
  else
    return false;
}

int findAnswer(int *arrA, int *arrB) {
  int maxx = 0;
  maxx = getPoint(arrA, arrB, maxx);
  for (int i = 0; i < N-1; i++) {
    for (int j = i+1; j < N; j++) {
      int cur_score = 0;
      if (isPlus(arrA, arrB, i, j)) {
	int *tmp = flipArr(arrB, i, j);
	cur_score = getPoint(arrA, tmp, maxx);
	if (cur_score > maxx) {
	  maxx = cur_score;
	}
	delete [] tmp;
      }
    }
  }
  return maxx;
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
