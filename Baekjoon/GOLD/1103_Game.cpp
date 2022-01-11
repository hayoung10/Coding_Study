#include <iostream>
#include <algorithm> // max
#include <cstring> // memset
using namespace std;

int m, n;
int map[50][50];
int dp[50][50];
bool visited[50][50];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	if(map[x][y] == 0) return 0;
	if (visited[x][y]) {
		cout << -1 << endl;
		exit(0);
	}
	if (dp[x][y] != -1) return dp[x][y];

	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + map[x][y] * dx[i];
		int ny = y + map[x][y] * dy[i];
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visited[x][y] = false;

	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') map[i][j] = 0;
			else map[i][j] = s[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << endl;

	return 0;
}