#include <cstdio>
#include <cmath>

using namespace std;

int answer;

int findMin(int num) {
  int n = 1;
  long long result;
  while (true) {
    result = 1;
    for (int i = 1; i <= n; i++) {
      result *= 3;
      result += 2;
    }
    if (result >= num)
      return n;
    n++;
  }
}

int findMax(int num) {
  int n = 1;
  long long result;
  while (true) {
    result = pow(3, n) + n*2;
    if (result > num)
      return n-1;
    n++;
  }
}



bool isPossible(int m_cnt, int p_cnt, long long cur, int dst) {
  long long minn, maxx;
  long long tmp = cur + p_cnt;
  for (int i = 0; i < m_cnt; i++) {
    tmp *= 3;
    tmp += 2;
  }
  maxx = tmp;
  p_cnt = p_cnt + m_cnt*2;
  minn = cur*pow(3, m_cnt) + p_cnt;

  if (dst >= minn && dst <= maxx)
    return true;
  else
    return false;
}

void dfs(int m_cnt, int p_cnt, long long cur, int dst) {
  // base cases
  if (cur > dst)
    return;
  if (m_cnt == 0 && p_cnt == 0) {
    if (cur == dst)
      answer++;
    return;
  }

  // cut off impossible cases
  if (!isPossible(m_cnt, p_cnt, cur, dst))
    return;

  if (m_cnt > 0)
    dfs(m_cnt-1, p_cnt+2, cur*3, dst);
  if (p_cnt > 0)
    dfs(m_cnt, p_cnt-1, cur+1, dst);
}

int solution(int num) {
  answer = 0;
  int minNum, maxNum;
  minNum = findMin(num);
  maxNum = findMax(num);

  for (int i = minNum; i <= maxNum; i += 3) {
    dfs(i, 0, 1, num);
  }
  return answer;
}

int main () {
  int N;
  scanf("%d", &N);
  solution(N);
  printf("%d\n", answer);
  
  return 0;
}
