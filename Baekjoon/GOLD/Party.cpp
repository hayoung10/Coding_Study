#include <iostream>
#include <algorithm> // sort
#include <cstring> // memset
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<pair<int, int>> road[1001];
int tmpTime[1001];
int home[1001] = { 0, };
int answer = 0;

void dijkstra(int start) {
	memset(tmpTime, -1, sizeof(tmpTime));
	tmpTime[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int time1 = pq.top().second;
		int cur = pq.top().first;
		pq.pop();

		for (int i = 0; i < road[cur].size(); i++) {
			int time2 = road[cur][i].second;
			int next = road[cur][i].first;

			if (tmpTime[next] == -1 || tmpTime[next] > time1 + time2) {
				tmpTime[next] = time1 + time2;
				pq.push({ next, tmpTime[next] });
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		road[a].push_back({ b,c });
	}

	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		dijkstra(i);
		home[i] = tmpTime[X];
	}
	dijkstra(X);
	for (int i = 1; i <= N; i++) {
		home[i] += tmpTime[i];
		answer = max(answer, home[i]);
	}
	cout << answer << endl;

	return 0;
}