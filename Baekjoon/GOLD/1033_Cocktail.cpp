#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, pair<int, int>>> graph[11];
long dp[11];

long gcd(long p, long q) {
	long r;
	while (q != 0) {
		r = p % q;
		p = q;
		q = r;
	}
	return p;
}

void dfs(int node, int parent) {
	for (auto n : graph[node]) {
		if (n.first == parent) continue;
		dp[n.first] = dp[node] * (long)n.second.second / (long)n.second.first;
		dfs(n.first, node);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long r = 1;
	int a, b, p, q;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> p >> q;
		graph[a].push_back({ b,{p,q} });
		graph[b].push_back({ a,{p,q} });
		r *= (p * q / gcd(p, q));
	}
	dp[0] = r;
	dfs(0, -1);
	
	long c = dp[0];
	for (int i = 1; i < N; i++) {
		if (dp[i] == 0) continue;
		c = gcd(c, dp[i]);
	}
	for (int i = 0; i < N; i++)
		cout << dp[i] / c << " ";
	cout << endl;

	return 0;
}