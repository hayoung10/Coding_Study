#include <iostream>
#include <algorithm> // min
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int dp[1001][3];
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

	int r, g, b;
	for (int i = 1; i < N; i++) {
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
	}
	int ans = min(min(dp[N - 1][0], dp[N - 1][1]), dp[N - 1][2]);
	cout << ans << endl;
	
	return 0;
}