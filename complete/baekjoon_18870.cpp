#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
vector<int> inputs;

void init() {
  cin >> N;
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    inputs.push_back(tmp);
  }
}

void find_answer() {
  vector<int> copied_inputs = inputs;
  map<int, int> m;
  sort(copied_inputs.begin(), copied_inputs.end());
  sort(unique(copied_inputs.begin(), copied_inputs.end()), copied_inputs.end());
  
  int counter = 0;
  for (auto i : copied_inputs) {
    m.insert({i, counter});
    counter++;
  }

  int new_value;
  for (auto i : inputs) {
    new_value = m.find(i)->second;
    cout << new_value << " ";
  }
  cout << "\n";
}

int main() {
  init();
  find_answer();
  

  
  return 0;
}
