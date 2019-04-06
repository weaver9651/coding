#include <iostream>
#include <vector>
#include <string>

using namespace std;


int count(int mask, vector<int> &words) {
  int cnt = 0;
  for (int word : words) {
    if ((word & ((1 << 26) - 1 - mask)) == 0) {
      cnt += 1;
    }
  }
  return cnt;
}

int go(int index, int k, int mask, vector<int> &words) {
  if (k < 0) return 0;

  // 알파벳을 끝까지 배우(거나 안배우)면 읽을 수 있는 가짓수 출력
  if (index == 26) return count(mask, words);

  int ans = 0;
  // 현재 index번째 알파벳을 배우고(=mask에 저장하고) 다음 index로 dfs
  // 단어를 배우면 단어를 배울 수 있는 슬롯 줄이기(k-1)
  int t1 = go(index + 1, k-1, mask | (1 << index), words);
  if (ans < t1) ans = t1;

  if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' &&
      index != 'i' - 'a' && index != 'c' - 'a') {
    // 'a', 'n', 't', 'i', 'c'는 무조건 배워야하므로 통과할 수 없음
    // 그 외의 단어를 안배운 case일 때도 계산해보기
    t1 = go(index + 1, k, mask, words);
    if (ans < t1) ans = t1;
  }
  return ans;
}

int main() {
  int N, K;
  vector<int> words(N);

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (char x : s) {
      words[i] |= (1 << (x - 'a'));
    }
  }

  cout << go(0, K, , words) << endl;

  return 0;
}
