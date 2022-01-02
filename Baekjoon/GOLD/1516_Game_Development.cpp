#include <iostream>
#include <algorithm> // max
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	int build_time[501];
	int entry[501];
	vector<int> order[501];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> build_time[i];
		while (true) {
			int a; cin >> a;
			if (a == -1) break;
			order[a].push_back(i);
			entry[i]++;
		}
	}

	queue<int> q;
	int ans[501];
	for (int i = 1; i <= N; i++) {
		if(entry[i] == 0) {
			q.push(i);
			ans[i] = build_time[i];
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < order[cur].size(); i++) {
			int next = order[cur][i];
			entry[next]--;

			ans[next] = max(ans[next], ans[cur] + build_time[next]);
			if (entry[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= N; i++)
		cout << ans[i] << endl;

	return 0;
}