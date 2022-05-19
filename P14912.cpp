// Math, BruteForce
// https://www.acmicpc.net/problem/14912

#include <iostream>

using namespace std;

int calcDigit(int x, int target) {
  int cnt = 0;
  while(x != 0) {
    int temp = x % 10;
    x /= 10;
    if (temp == target) {
      cnt++;
    }
  }
  return cnt;
}

int main() {

  int n, d, cnt = 0;
  cin >> n >> d;

  for (int i = 1; i <= n; i++) {
    cnt += calcDigit(i, d);
  }

  cout << cnt;

}
