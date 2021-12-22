#include <iostream>
#include <vector>
using namespace std;

#define INF 987654321
int N, M;

int main()
{
	cin >> N >> M;
	vector<vector<int>> weight(N + 1, vector<int>(N + 1, INF));
	vector<vector<int>> answer(N + 1, vector<int>(N + 1, 0));

	int a, b, w;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> w;
		weight[a][b] = w;
		weight[b][a] = w;
		answer[a][b] = b;
		answer[b][a] = a;

		if (i < N)
			weight[i + 1][i + 1] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (weight[i][j] > weight[i][k] + weight[k][j]) {
					weight[i][j] = weight[i][k] + weight[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!answer[i][j]) cout << "- ";
			else
				cout << answer[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}