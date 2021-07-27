#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, maxdepth = 0;
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    vector<int> depth(n + 1, 0);

    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        graph[edge[i][0]][edge[i][1]] = true;
        graph[edge[i][1]][edge[i][0]] = true;
    }

    q.push(1); // start node : 1
    visited[1] = true;

    while (!q.empty()) {
        int present = q.front();
        q.pop();

        for (int i = 2; i <= n; i++) { // Check
            if (graph[present][i] == true && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                depth[i] = depth[present] + 1;

                if (depth[i] > maxdepth)
                    maxdepth = depth[i];
            }
        }
    }

    for (int i = 1; i <= n; i++)
        if (depth[i] == maxdepth) // count
            answer++;

    return answer;
}

int main()
{
    cout << "n \tvertex \t\t\t\t\t\t\t\treturn" << endl;
    cout << "6 \t[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]] \t" << solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} }) << endl;

    return 0;
}