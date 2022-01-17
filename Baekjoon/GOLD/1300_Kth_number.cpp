#include <iostream>
#include <algorithm> // min
using namespace std;

long long N, K;

long long count(long long m) {
	long long sum = 0;
	for (int i = 1; i <= N; i++)
		sum += min(m / i, N);

	return sum;
}

int main()
{
	cin >> N >> K;
	K = min((long long)1000000000, K);

	long long left = 1, right = N * N;
	long long mid, cnt;

	while (left <= right) {
		mid = (left + right) / 2;

		cnt = count(mid);
		if (cnt >= K)
			right = mid - 1;
		else
			left = mid + 1;
	}
	cout << left << endl;

	return 0;
}