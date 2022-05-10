// Max Flow
// https://www.acmicpc.net/problem/6086

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define VERTEX 501
#define INF 10000000000

using namespace std;

vector<long long> Graph[VERTEX];
long long result = 0;
long long capacity[VERTEX][VERTEX], flow[VERTEX][VERTEX], path[VERTEX];


int Transfer(char ch) {
    if(ch <= 'Z') {
        return ch - 'A';
    }
    return ch - 'a' + 26;
}


bool BFS(long long source, long long sink) {
    // 현재 Capacity 상황을 바탕으로Source -> Sink 까지 도달 가능한 모든 경로를 추출하여 path에 저장
    fill(path, path + VERTEX, -1);
        queue<long long> q;
        q.push(source);
        while(!q.empty()) {
            long long from = q.front();
            q.pop();
            for (int i = 0; i< Graph[from].size(); i++) {
                long long to = Graph[from][i];
                if (capacity[from][to] - flow[from][to] > 0 && path[to] == -1) {
                    // 흐를수 있는 용량이 1이상이면서 방문한 정점이 아닌경우 큐에 삽입
                    q.push(to);
                    path[to] = from;
                    if (to == sink) break;
                }
            }
        }

        if(path[sink] == -1) return false; // 현재 Capacity 상황으로 도달 불가하면 false
        return true;
}

void getMaxFlow(long source, long sink) {

    while(BFS(source, sink)) {

        long long flowValue = INF;
        for (int i = sink; i != source; i = path[i]) {
            // BFS로 계산한 Source -> Sink 경로를 순회하면서 통과할 수 있는 최대유량 계산
            long long from = path[i];
            long long to = i;
            flowValue = min(flowValue, capacity[path[i]][i] - flow[path[i]][i]);
        }


        for (int i = sink; i != source; i = path[i]) {
            flow[path[i]][i] += flowValue; // 정방향 flow 
            flow[i][path[i]] -= flowValue; // 역방향 flow
        }
        
        result += flowValue;
    }
}


int main() {

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char from, to;
        int value;
        cin >> from >> to >> value;

        int fromInt = Transfer(from);
        int toInt = Transfer(to);

        
        Graph[fromInt].push_back(toInt); // 양의 방향 flow
        Graph[toInt].push_back(fromInt); // 음의 방향 flow
        capacity[fromInt][toInt] = capacity[fromInt][toInt] + value; // 양의 방향 flow의 capacity설정 
        capacity[toInt][fromInt] = capacity[toInt][fromInt] + value; // 양의 방향 flow의 capacity설정 

    }
    
    getMaxFlow(Transfer('A'), Transfer('Z'));
    cout << result << endl;

}
