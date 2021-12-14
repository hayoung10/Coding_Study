#include <iostream>
#include <map>
using namespace std;

int N, K;
int sum[200001];
map<int, long long> m;

int main()
{
	cin >> N >> K;

	int A;
	sum[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A;
		sum[i] = sum[i - 1] + A;
	}

	long long ans = 0;
	for (int i = 1; i <= N; i++) {
		if (sum[i] == K) ans++;

		ans += m[sum[i] - K];
		m[sum[i]]++;
	}
	cout << ans << endl;

	return 0;
}