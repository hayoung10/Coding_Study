#include <iostream>
#include <queue>
using namespace std;

int M, N;
int maze[101][101];
int dist[101][101];
int d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0,0 }); // start
	dist[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + d[i][0];
			int dy = y + d[i][1];
			if (dx < 0 || dy < 0 || dx >= N || dy >= M) continue;
			if (maze[dx][dy]) { // 1
				if (dist[dx][dy] > dist[x][y] + 1) {
					dist[dx][dy] = dist[x][y] + 1;
					q.push({ dx,dy });
				}
			} else { // 0
				if (dist[dx][dy] > dist[x][y]) {
					dist[dx][dy] = dist[x][y];
					q.push({ dx,dy });
				}	
			}
		}
	}
}

int main()
{
	cin >> M >> N;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			dist[i][j] = 987654321;
			maze[i][j] = str[j] - '0';
		}
	}
	bfs();
	cout << dist[N - 1][M - 1] << endl;

	return 0;
}