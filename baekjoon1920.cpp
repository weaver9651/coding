#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  Node *next;
  int data;
  Node(int data);
};

Node::Node(int data) {
  this->data = data;
  this->next = NULL;
}

class HT { // HashTable
private:
  int HT_size;
public:
  Node** arr;
  HT(int size);
  void insert(int data);
  bool find(int data);
};

HT::HT(int size) {
  HT_size = size;
  arr = new Node*[size];
  for (int i = 0; i < size; i++)
    arr[i] = NULL;
}

bool HT::find(int data) {
  int index = data % HT_size;
  Node *tmp = arr[index];
  while (tmp) {
    if (tmp->data == data)
      return true;
  }
  return false;
}

void HT::insert(int data) {
  int index = data % HT_size;
  Node *tmp = arr[index];
  if (!find(data)) {
    arr[index] = new Node(data);
    arr[index]->next = tmp;
  }
}

int main () {
  HT ht = HT(61);
  int N;
  scanf("%d", &N);
  int tmp;
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    ht.insert(tmp);
  }

  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &tmp);
    printf("%d\n", ht.find(tmp) ? 1 : 0);
  }
  
  return 0;
}
