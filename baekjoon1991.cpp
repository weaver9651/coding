#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  char name;
  Node* left;
  Node* right;
  Node(char name, Node* left=NULL, Node* right=NULL);
  ~Node();
};

Node::Node(char name, Node* left, Node* right) {
  this->name = name;
  this->left = left;
  this->right = right;
}

class Tree{
public:
  Node* root;

  Tree() { this->root = new Node('A');  };
  ~Tree();
  Node* wfindNode(Node* start, char targetName);
  Node* findNode(char targetName);
  
  void insertNode(char parentName, char leftName, char rightName);

  void preorder(Node* node);
  void inorder(Node* node);
  void  postorder(Node* node);
};

void Tree::postorder(Node* node) {
  if (node->left)
    postorder(node->left);
  if (node->right)
    postorder(node->right);
  if (node)
    cout << node->name;
}

void Tree::inorder(Node* node) {
  if (node->left)
    inorder(node->left);
  if (node)
    cout << node->name;
  if (node->right)
    inorder(node->right);
}

void Tree::preorder(Node* node) {
  if (node)
    cout << node->name;

  if (node->left)
    preorder(node->left);
  if (node->right)
    preorder(node->right);
}

Node* Tree::wfindNode(Node* start, char targetName) {
  Node* curNode = start;
  if (curNode == NULL)
    return NULL;
  if (curNode->name == targetName)
    return curNode;
  else {
    if(Node* result = wfindNode(curNode->left, targetName))
      return result;
    if (Node* result = wfindNode(curNode->right, targetName))
      return result;
  }
}

Node* Tree::findNode(char targetName) {
  return wfindNode(this->root, targetName);
}

void Tree::insertNode(char parentName, char leftName, char rightName) {
  Node* parent = findNode(parentName);
  if (leftName == '.')
    parent->left = NULL;
  else
    parent->left = new Node(leftName);
  if (rightName == '.')
    parent->right = NULL;
  else
    parent->right = new Node(rightName);
}

int main () {
  Tree *tree = new Tree();
  int N;
  scanf("%d", &N);

  char parent, left, right;
  char tmp;
  scanf("%c", &tmp); // remove newline
  for (int i = 0; i < N; i++) {
    scanf("%c%c%c%c%c", &parent, &tmp, &left, &tmp, &right);
    scanf("%c", &tmp); // remove newline
    tree->insertNode(parent, left, right);
  }

  tree->preorder(tree->root);
  cout << endl;
  tree->inorder(tree->root);
  cout << endl;
  tree->postorder(tree->root);
  cout << endl;
  
  return 0;
}
