#include <iostream>
#include <vector>
using namespace std;

int N;
int travel_time[21][21];
int map[21][21];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> travel_time[i][j];
			map[i][j] = travel_time[i][j];
		}
	}

	// floyd-warshall
	for (int b = 1; b <= N; b++) { // a->b->c
		for (int a = 1; a <= N; a++) {
			for (int c = 1; c <= N; c++) {
				if ((a == b) || (b == c)) continue;
				if (travel_time[a][c] > travel_time[a][b] + travel_time[b][c]) {
					cout << -1 << endl;
					return 0;
				} else if (travel_time[a][c] == travel_time[a][b] + travel_time[b][c])
					map[a][c] = 0;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans += map[i][j];
	cout << ans / 2 << endl;

	return 0;
}