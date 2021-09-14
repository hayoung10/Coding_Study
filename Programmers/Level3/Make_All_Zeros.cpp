#include <iostream>
#include <vector>
using namespace std;

long long answer = 0;

void dfs(vector<vector<int>> graph, vector<long long>& w, int node, int parent) {
    for (int i = 0; i < graph[node].size(); i++)
        if (graph[node][i] != parent)
            dfs(graph, w, graph[node][i], node);
    w[parent] += w[node];
    answer += abs(w[node]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long sum = 0;
    vector<long long> w(a.size());
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        w[i] = a[i]; // 형변환
    }
    if (sum != 0) return -1; // 불가능

    vector<vector<int>> graph(a.size()); // 각 정점에 연결된 edge들
    for (int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(graph, w, 0, 0);

    if (w[0] == 0) return answer;
    return -1;
}

int main()
{
    cout << "a \t\tedges \t\t\t\tresult" << endl;
    cout << "[-5,0,2,1,2] \t[[0,1],[3,4],[2,3],[0,3]] \t" << solution({ -5,0,2,1,2 }, { {0,1},{3,4},{2,3},{0,3} }) << endl;
    cout << "[0,1,0] \t[[0,1],[1,2]] \t\t\t" << solution({ 0,1,0 }, { {0,1},{1,2} }) << endl;

    return 0;
}