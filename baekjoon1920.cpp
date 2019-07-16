#include <cstdio>

using namespace std;

int N, M;

void merge(int *arr, int start, int end) {
  int mid = (start + end) / 2;
  int *newarr = new int[end - start + 1];
  int i = start;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= end) {
    if (arr[i] < arr[j]) {
      newarr[k] = arr[i];
      i++;
      k++;
    }
    else {
      newarr[k] = arr[j];
      j++;
      k++;
    }
  }
  while (i <= mid) {
    newarr[k] = arr[i];
    i++;
    k++;
  }
  while (j <= end) {
    newarr[k] = arr[j];
    j++;
    k++;
  }
  for (int idx = 0; idx < end - start + 1; idx++) {
    arr[idx + start] = newarr[idx];
  }
}

void mergesort(int *arr, int start, int end) {
  if (start == end)
    return;
  
  int mid = (start + end) / 2;
  mergesort(arr, start, mid);
  mergesort(arr, mid + 1, end);
  merge(arr, start, end);
}

int findNum(int *arr, int num, int start, int end) {
  while (start != end) {
    int mid = (start + end) / 2;
    if (arr[mid] == num) {
      return 1;
    }
    else {
      if (num > arr[mid]) {
	start = mid + 1;
      }
      else { // num < arr[mid]
	end = mid;
      }
    }
  }
  if (arr[start] == num)
    return 1;
  else
    return 0;
}

int main () {
  scanf("%d", &N);
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    scanf("%d", &arr[i]);
  }

  scanf("%d", &M);
  int *target = new int[M];
  for (int i = 0; i < M; i++) {
    scanf("%d", &target[i]);
  }


  mergesort(arr, 0, N-1);

  for (int i = 0; i < M; i++) {
    int value = findNum(arr, target[i], 0, N-1);
    printf("%d\n", value);
  }
  
  return 0;
}
