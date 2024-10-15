#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int arr[10001] = {0,};
int stack_pos = -1;

bool is_empty_arr() {
    return stack_pos < 0;
}

int main() {
    vector<int> answer;
    cin >> N;
    string op;
    string tmp;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> op;
        if (op.compare("push") == 0) {
            cin >> tmp;
            num = stoi(tmp);
            
            // push
            arr[++stack_pos] = num;
        } else if (op.compare("pop") == 0) {
            if (is_empty_arr()) {
                // cout << -1 << "\n";
                answer.push_back(-1);
            } else {
                // cout << arr[stack_pos--] << "\n";
                answer.push_back(arr[stack_pos--]);
            }
        } else if (op.compare("top") == 0) {
            if (is_empty_arr()) {
                // cout << -1 << "\n";
                answer.push_back(-1);
            } else {
                // cout << arr[stack_pos] << "\n";
                answer.push_back(arr[stack_pos]);
            }
        } else if (op.compare("empty") == 0) {
            if (is_empty_arr()) {
                // cout << 1 << "\n";
                answer.push_back(1);
            } else {
                // cout << 0 << "\n";
                answer.push_back(0);
            }
        } else if (op.compare("size") == 0) {
            // cout << stack_pos + 1 << "\n";
            answer.push_back(stack_pos + 1);
        }
    }

    for (int ans : answer) {
        cout << ans << "\n";
    }


    return 0;
}