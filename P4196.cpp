// SCC
// https://www.acmicpc.net/problem/4196
// 해당 문제는 SCC와 관련있지만 역방향 탐색은 할 필요가 없음
// 스택의 마지막 node로부터 도달 가능한 node를 모두 한 번에 쓰러트릴수 있는 도미노로 판단.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool visited[100001];
vector<vector<int>> vec;
stack<int> st;

void DFS(int node) {
  visited[node] = true;
  for (auto next : vec[node]) {
    if(!visited[next]) DFS(next);
  }
  st.push(node);
} 

void runner() {
  int n, m;
  cin >> n >> m;
  vec.clear();
  vec.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;
    vec[from].push_back(to);
  }

  fill_n(visited, sizeof visited, 0);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) DFS(i);
  }

  fill_n(visited, sizeof visited, 0);
  int ans = 0;
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    if (!visited[cur]) {
      DFS(cur);
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    runner();
  }
}
