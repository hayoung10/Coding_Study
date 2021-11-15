#include <iostream>
using namespace std;

int N, S, M;
bool dp[51][1001];

int main()
{
	cin >> N >> S >> M;

	dp[0][S] = true;
	int vol;
	for (int i = 1; i <= N; i++) {
		cin >> vol;
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j]) {
				if (j + vol <= M) dp[i][j + vol] = true;
				if (j - vol >= 0) dp[i][j - vol] = true;
			}
		}
	}

	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}