// DP
// https://www.acmicpc.net/problem/9655

#include<iostream>

using namespace std;

int main() {

    int N;
    int DP [1001];
    
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;

    cin >> N;
    
    for (int i = 3; i <= N; i++) {
        DP[i] = min((DP[i - 1] + 1), DP[i - 3] + 1);
    }

    if (DP[N] % 2 == 1) {
        cout << "SK";
    } else {
        cout << "CY";
    }

}