#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int N, M;
bool graph[1001][1001];
int visited[1001][1001][2];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1},1 }); // {{x,y},block}
	visited[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == N && y == M) return visited[x][y][block];

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
				if (graph[nx][ny] == 1 && block) {
					visited[nx][ny][block - 1] = visited[x][y][block] + 1;
					q.push({ {nx,ny},block - 1 });
				}
				if (graph[nx][ny] == 0 && visited[nx][ny][block] == 0) {
					visited[nx][ny][block] = visited[x][y][block] + 1;
					q.push({ {nx,ny},block });
				}
			}
		}
	}

	return -1;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf_s("%1d", &graph[i][j]);

	cout << bfs() << endl;

	return 0;
}