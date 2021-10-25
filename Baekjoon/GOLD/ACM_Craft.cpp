#include <iostream>
#include <algorithm> // max
#include <cstring> // memset
#include <vector>
#include <queue>
using namespace std;

int T, N, K, W;
int buildtime[1001];
int dp[1001];
int indegree[1001];
vector<int> order[1001];

int main()
{
	cin >> T; // testcase
	for (int i = 0; i < T; i++) {
		// Initialize
		memset(buildtime, 0, sizeof(buildtime));
		memset(dp, 0, sizeof(dp));
		memset(indegree, 0, sizeof(indegree));
		memset(order, 0, sizeof(order));

		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> buildtime[i];
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			order[X].push_back(Y);
			indegree[Y]++;
		}
		cin >> W;

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dp[i] = buildtime[i];
			}
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < order[cur].size(); i++) {
				int next = order[cur][i];
				dp[next] = max(dp[next], dp[cur] + buildtime[next]);
				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
			}
		}
		cout << dp[W] << endl;
	}

	return 0;
}