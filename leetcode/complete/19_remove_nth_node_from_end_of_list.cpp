#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct LinkedList {
  ListNode* head;
  LinkedList() { head = nullptr; };
  void addNode(int val);
  void printAll();
  ListNode* removeNthFromEnd(ListNode* head, int n);
};

int main() {
  LinkedList* list = new LinkedList();
  vector<int> numList = {1, 2, 3, 4, 5};
  for_each(numList.begin(), numList.end(), [list] (int num) -> void { list->addNode(num);});

  list->removeNthFromEnd(list->head, 3);
  list->printAll();

  return 0;
}

ListNode* LinkedList::removeNthFromEnd(ListNode* head, int n) {
      ListNode *beforeHead = new ListNode(0, head);
    int listSize = 0;
    ListNode *nextNode = head;
    while(nextNode) {
        listSize++;
        nextNode = nextNode->next;
    }
    // cout << listSize;
    int cnt = 0;
    int targetIdx = listSize - n + 1; // 1
    ListNode *prevNode = beforeHead;
    while(cnt < targetIdx - 1) {
        prevNode = prevNode->next;
        cnt++;
    }
    // Now prevNode is right before target node
    ListNode *targetNode = prevNode->next; // could be head
    nextNode = targetNode->next; // could be null
    // cout << targetNode->val;
    // cout << head->val;
    prevNode->next = nextNode;
    targetNode->next = NULL;
    if (targetNode == head) {
        head = nextNode;
    }
    delete targetNode;
    
    return head;    
}

void LinkedList::addNode(int val) {
  if (this->head == nullptr) {
    this->head = new ListNode(val);
    return;
  }
  ListNode* prevNode = head;
  while (prevNode->next) {
    prevNode = prevNode->next;
  }
  prevNode->next = new ListNode(val);
}

void LinkedList::printAll() {
  ListNode* node = this->head;
  while (node) {
    cout << node->val << endl;
    node = node->next;
  }
}