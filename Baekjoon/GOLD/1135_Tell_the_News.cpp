#include <iostream>
#include <algorithm> // sort, max
#include <vector>
using namespace std;

int N;
vector<int> parents[51];

int dfs(int node, int pnode) { // top-down
	int ret = 0;
	vector<int> v;
	for (int i = 0; i < parents[node].size(); i++) {
		int child = parents[node][i];
		v.push_back(dfs(child, node));
	}

	sort(v.begin(), v.end(), greater<>());
	for (int i = 0; i < v.size(); i++)
		ret = max(ret, v[i] + i + 1);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int pnode;
	for (int i = 0; i < N; i++) {
		cin >> pnode;
		if (pnode == -1) continue;
		parents[pnode].push_back(i);
	}
	int ans = dfs(0, -1);
	cout << ans << endl;

	return 0;
}