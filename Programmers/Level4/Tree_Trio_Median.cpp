#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

multimap<int, int> m;

vector<int> bfs(int start, int n) {
	vector<bool> visited(n, false);
	queue<int> q;
	q.push(start);
	visited[start - 1] = true;
	vector<int> depth(n, 0);

	while (!q.empty()) {
		int p = q.front();
		q.pop();

		for (auto it = m.lower_bound(p); it != m.upper_bound(p); it++) {
			if (!visited[it->second - 1]) {
				visited[it->second - 1] = true;
				q.push(it->second);
				depth[it->second - 1] = depth[p - 1] + 1;
			}
		}
	}

	return depth;
}

int solution(int n, vector<vector<int>> edges) {
	int answer = 0;

	for (int i = 0; i < edges.size(); i++) {
		m.insert(make_pair(edges[i][0], edges[i][1]));
		m.insert(make_pair(edges[i][1], edges[i][0]));
	}
	
	vector<int> tdepth = bfs(1, n);
	int node = 0;
	int maxdepth = 0;
	for (int i = 0; i < tdepth.size(); i++) {
		if (maxdepth <= tdepth[i]) {
			node = i + 1;
			maxdepth = tdepth[i];
		}
	}

	for (int i = 0; i < 2; i++) {
		vector<int> tdepth2 = bfs(node, n);
		node = 0;
		maxdepth = 0;
		for (int j = 0; j < tdepth2.size(); j++) {
			if (maxdepth <= tdepth2[j]) {
				node = j + 1;
				maxdepth = tdepth2[j];
			}
		}
		if (count(tdepth2.begin(), tdepth2.end(), maxdepth) > 1)
			return maxdepth;
	}

	return maxdepth - 1;
}

int main()
{
	cout << "n \tedges \t\t\t result" << endl;
	cout << "4 \t[[1,2],[2,3],[3,4]] \t" << solution(4, { {1,2},{2,3},{3,4} }) << endl;

	return 0;
}