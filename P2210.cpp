// Graph, BFS, DFS
// https://www.acmicpc.net/problem/2210

#include <iostream>
#include <set>

using namespace std;

int CNT = 0;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};

set<string> mySet;

void BFS(string graph[][5], int y, int x, int cnt, string str) {
    if (cnt == 6) {
        if (mySet.find(str) == mySet.end()) {
            CNT++;
            mySet.insert(str);
            return;
        } else {
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) {
            continue;
        }

        BFS(graph, ny, nx, cnt+1, str + graph[y][x]);
    }
}

int main() {

    string graph[5][5];
    for (int i = 0; i < 5; i++) {
        string val;
        for (int j = 0; j < 5; j++) {
            cin >> val;
            graph[i][j] = val;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            BFS(graph, i, j, 0, "");
        }
    }
    cout << CNT;

}