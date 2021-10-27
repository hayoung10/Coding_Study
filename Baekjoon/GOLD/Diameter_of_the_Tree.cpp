#include <iostream>
#include <cstring> // memset
#include <vector>
using namespace std;

int V, sumWeight = 0, endNode;
vector<pair<int, int>> tree[100001]; // pair : <node, weight>
bool visited[100001] = { false, };

void dfs(int node, int weight) {
	if (visited[node]) return;
	visited[node] = true;

	if (sumWeight < weight) {
		sumWeight = weight;
		endNode = node;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		dfs(tree[node][i].first, weight + tree[node][i].second);
	}
}

int main()
{
	cin >> V;

	int to, from, weight;
	for (int i = 0; i < V; i++) {
		cin >> to;
		while (true) {
			cin >> from;
			if (from == -1) break;
			cin >> weight;
			tree[to].push_back({ from,weight });
			tree[from].push_back({ to,weight });
		}
	}
	dfs(1, 0);

	sumWeight = 0;
	memset(visited, false, sizeof(visited));
	dfs(endNode, 0);

	cout << sumWeight << endl;

	return 0;
}