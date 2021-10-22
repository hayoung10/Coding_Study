#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int N, rem_n; // rem_n : remove node
vector<vector<int>> graph;
vector<int> child;

void dfs(int node, int sibling) {
	if (node == rem_n) {
		if (sibling == 1)
			answer++;
		return;
	}
	if (child[node] == 0) {
		answer++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (graph[node][i] == 0) continue;
		dfs(i, child[node]);
	}
}

int main()
{
	cin >> N;
	graph = vector<vector<int>>(N, vector<int>(N, 0));
	child = vector<int>(N, 0);

	int root;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == -1) {
			root = i;
			continue;
		}
		graph[num][i]++;
		child[num]++;
	}
	cin >> rem_n;

	if (child[root] == 0 && root != rem_n)
		answer = 1;
	else
		dfs(root, child[root]);
	cout << answer << endl;

	return 0;
}