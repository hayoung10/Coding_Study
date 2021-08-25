#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < edge_list.size(); i++) { // edge 정보 만들기
		graph[edge_list[i][0]].push_back(edge_list[i][1]);
		graph[edge_list[i][1]].push_back(edge_list[i][0]);
	}
	vector<vector<int>> DP(k, vector<int>(n + 1, INF));
	DP[0][gps_log[0]] = 0; // 첫 거점으로 초기화
	for (int p = 1; p < k; p++) {
		for (int q = 1; q <= n; q++) {
			int minCount = DP[p - 1][q];
			for (int r = 0; r < graph[q].size(); r++)
				minCount = min(minCount, DP[p - 1][graph[q][r]]);

			DP[p][q] = minCount;
			if (q != gps_log[p]) // 오류 -> 수정 필요
				DP[p][q]++;
		}
	}

	if (DP[k - 1][gps_log[k - 1]] < INF)
		return DP[k - 1][gps_log[k - 1]];

	return -1;
}

int main()
{
	cout << "변수명 \t\t값" << endl;
	cout << "n \t\t7" << endl;
	cout << "m \t\t10" << endl;
	cout << "edge_list \t[[1, 2], [1, 3], [2, 3], [2, 4], [3, 4], [3, 5], [4, 6], [5, 6], [5, 7], [6, 7]]" << endl;
	cout << "k \t\t6" << endl;
	cout << "gps_log \t[1, 2, 3, 3, 6, 7]" << endl;
	cout << "answer \t\t";
	int ans1 = solution(7, 10, { {1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7} }, 6, { 1,2,3,3,6,7 });
	cout << ans1 << endl << endl;

	cout << "n \t\t7" << endl;
	cout << "m \t\t10" << endl;
	cout << "edge_list \t[[1, 2], [1, 3], [2, 3], [2, 4], [3, 4], [3, 5], [4, 6], [5, 6], [5, 7], [6, 7]]" << endl;
	cout << "k \t\t6" << endl;
	cout << "gps_log \t[1, 2, 4, 6, 5, 7]" << endl;
	cout << "answer \t\t";
	int ans2 = solution(7, 10, { {1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7} }, 6, { 1,2,4,6,5,7 });
	cout << ans2 << endl;

	return 0;
}