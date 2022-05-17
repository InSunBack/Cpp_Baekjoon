// Queue
// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

  int N, card;
  cin >> N;

  queue<int> que;

  for (int i = 1; i <= N; i++) {
    que.push(i);
  }

  while (!que.empty()) {
    card = que.front();
    que.pop();
    que.push(que.front());
    que.pop();
  }

  cout << card;
 
}
