#include <iostream>
#include <algorithm> // min
#include <vector>
#include <queue> // priority_queue
using namespace std;

#define INF 987654321

int N, E, v1, v2;
vector<pair<int, int>> graph[801];
int dist[801];

void dijkstra(int start) {
	for (int i = 0; i <= N; i++) dist[i] = INF;
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curDist = pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = graph[cur][i].second;
			if (dist[next] > curDist + nextDist) {
				dist[next] = curDist + nextDist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> N >> E;
	int a, b, c;
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	cin >> v1 >> v2;

	dijkstra(1);
	int s_v1 = dist[v1];
	int s_v2 = dist[v2];

	dijkstra(v1);
	int v1_v2 = dist[v2];
	int v1_N = dist[N];

	dijkstra(v2);
	int v2_N = dist[N];

	int ans = INF;
	ans = min(ans, s_v1 + v1_v2 + v2_N);
	ans = min(ans, s_v2 + v1_v2 + v1_N);
	if (v1_v2 == INF || ans == INF) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}