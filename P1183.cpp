// Math, Sotring
// https://www.acmicpc.net/problem/1183

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B;
    cin >> N;

    vector<int> ints(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        ints[i] = A - B;
    }

    sort(ints.begin(), ints.end());

    if (N % 2 == 1) {
        cout << 1;
    } else {
        cout << ints[N / 2] - ints[(N / 2) - 1] + 1;
    }
}