#include <iostream>
#include <cmath> // sqrt, max
using namespace std;

bool isSquare(int num) { // Á¦°ö¼öÀÎÁö È®ÀÎ
	int root = sqrt(num); // Á¦°ö±Ù
	if (root * root == num) return true;
	return false;
}

int main()
{
	int N, M;
	int arr[9][9];

	cin >> N >> M;
	string a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		for (int j = 0; j < M; j++) {
			arr[i][j] = a[j] - '0';
		}
	}

	int answer = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int dx = -N + 1; dx < N; dx++) {
				for (int dy = -M + 1; dy < M; dy++) {
					if (dx == 0 && dy == 0) {
						if (isSquare(arr[i][j]))
							answer = max(answer, arr[i][j]);
						continue;
					}
					int x = i + dx, y = j + dy;
					if (x < 0 || x >= N || y < 0 || y >= M) continue;

					int curr = arr[i][j];
					while (0 <= x && x < N && 0 <= y && y < M) {
						curr = curr * 10 + arr[x][y];
						if (isSquare(curr))
							answer = max(answer, curr);
						x += dx;
						y += dy;
					}
				}
			}
		}
	}
	cout << answer << endl;

	return 0;
}