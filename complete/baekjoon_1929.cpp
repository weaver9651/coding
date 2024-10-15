#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_prime(vector<int> &prime_nums, int new_num) {
    for (auto prime : prime_nums) {
        if (prime > sqrt(new_num))
            break;

        if (new_num % prime == 0) {
            return false;
        }
    }
    return true;
}

vector<int> find_prime_nums(int end) {
    vector<int> result;
    for (int i = 2; i <= end; i++) {
        if (i == 2) {
            result.push_back(2);
            continue;
        }
        if (is_prime(result, i)) {
            result.push_back(i);
        }
    }
    
    return result;
}

int main() {
    int start;
    int end;
    cin >> start >> end;
    vector<int> prime_nums = find_prime_nums(end);
    for (auto prime : prime_nums) {
        if (prime < start)
            continue;
        cout << prime << "\n";
    }

    return 0;
}