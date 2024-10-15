#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<char, pair<char, char>> graph;

void init() {
    cin >> N;
    char root, left, right, tmp;
    scanf("%c", &tmp); // remove newline
    for (int i = 0; i < N; i++) {
        scanf("%c%c", &root, &tmp);
        scanf("%c%c", &left, &tmp);
        scanf("%c%c", &right, &tmp);
        // cout << root << left << right << endl;
        graph.insert(make_pair(root, make_pair(left, right)));
    }
}

void preorder() {
    vector<bool> visit(N, false);
    vector<char> nodes;
    nodes.push_back('A');
    visit[0] = true;
    while (!nodes.empty()) {
        char cur = nodes.back();
        nodes.pop_back();

        auto children = graph[cur];
        char left = children.first;
        char right = children.second;

        cout << cur << flush;

        if (right != '.' && !visit[right - 'A']) {
            visit[right - 'A'] = true;
            nodes.push_back(right);
        }
        if (left != '.' && !visit[left - 'A']) {
            visit[left - 'A'] = true;
            nodes.push_back(left);
        }
    }
    cout << "\n";
}

void inorder() {
    vector<bool> visit(N, false);
    vector<char> nodes;
    nodes.push_back('A');
    while (!nodes.empty()) {
        char cur = nodes.back();
        nodes.pop_back();

        auto children = graph[cur];
        char left = children.first;
        char right = children.second;

        if (left != '.' && !visit[left - 'A']) {
            nodes.push_back(cur);
            nodes.push_back(left);
            continue;
        }

        cout << cur << flush;
        visit[cur - 'A'] = true;

        if (right != '.' && !visit[right - 'A']) {
            visit[right - 'A'] = true;
            nodes.push_back(right);
        }
    }
    cout << "\n";
}

void postorder() {
    vector<bool> visit(N, false);
    vector<char> nodes;
    nodes.push_back('A');
    while (!nodes.empty()) {
        char cur = nodes.back();
        nodes.pop_back();

        auto children = graph[cur];
        char left = children.first;
        char right = children.second;

        if (left != '.' && !visit[left - 'A']) {
            nodes.push_back(cur);
            nodes.push_back(left);
            continue;
        }


        if (right != '.' && !visit[right - 'A']) {
            nodes.push_back(cur);
            nodes.push_back(right);
            continue;
        }

        cout << cur << flush;
        visit[cur - 'A'] = true;
    }
    cout << "\n";
}

int main() {
    init();
    // preorder:
    // 자신 출력
    // 왼쪽 노드가 있으면 방문, 없으면 오른쪽 노드 방문
    preorder();

    // inorder:
    // 왼쪽 노드가 있으면 방문, 없으면 자신 출력
    // 오른쪽 노드 방문
    inorder();

    // postorder:
    // 왼쪽 노드가 있으면 방문,
    // 오른쪽 노드가 있으면 방문, 없으면 자신 출력
    postorder();

    return 0;
}