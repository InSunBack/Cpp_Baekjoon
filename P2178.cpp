// Graph, BFS
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int row, col;
int graph [101][101];
bool visited [101][101];

struct Node {
    int y;
    int x;
    int cnt;
};


int BFS(int y_, int x_) {
    queue<Node> q;

    q.push(Node{y_, x_, 1});
    visited[y_][x_] = true;

    while(!q.empty()) {
        Node node = q.front();
        q.pop();
        int y = node.y;
        int x = node.x;

        if (y == (row - 1) && x == (col - 1)) {
            return node.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= row || nx >= col) {
                continue;
            }
            if (visited[ny][nx] == true) {
                continue;
            }

            if (graph[ny][nx] == 1) {
                visited[ny][nx] = true;
                q.push(Node{ny, nx, node.cnt + 1});
            }
        }
    }
    return -1;
}

int main() {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < col; j++) {
            graph[i][j] = int(str[j]) - 48;
        }
    }

    cout << BFS(0, 0);
}
