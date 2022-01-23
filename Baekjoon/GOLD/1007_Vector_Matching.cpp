#include <iostream>
#include <algorithm> // min
#include <cstring> // memset
#include <cmath> // sqrt, pow
using namespace std;

int T, N;
pair<int, int> dots[21];
bool visited[21];
double ans;

void dfs(int cur, int cnt) {
	if (cnt == N / 2) {
		int sum_x = 0, sum_y = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				sum_x -= dots[i].first;
				sum_y -= dots[i].second;
			} else {
				sum_x += dots[i].first;
				sum_y += dots[i].second;
			}
		}
		ans = min(ans, sqrt(pow(sum_x, 2) + pow(sum_y, 2)));

		return;
	}

	for (int i = cur; i < N; i++) {
		visited[i] = true;
		dfs(i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		memset(dots, 0, sizeof(dots));

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> dots[i].first >> dots[i].second;

		ans = 1e9 + 7;
		dfs(0, 0);
		printf("%.12f\n", ans);
	}

	return 0;
}