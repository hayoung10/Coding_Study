#include <iostream>
using namespace std;

int N, Q; // Q : question number
long long arr[21];
long long ans[21];
bool check[21] = { false, };

int main()
{
	cin >> N;
	arr[0] = 1;
	for (int i = 1; i < 21; i++)
		arr[i] = arr[i - 1] * i;

	cin >> Q;
	if (Q == 1) {
		long long k;
		cin >> k;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[j]) continue;
				if (arr[N - i - 1] < k) {
					k -= arr[N - i - 1];
				}
				else {
					ans[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	else if (Q == 2) {
		long long cnt = 0;
		int cmp;
		for (int i = 0; i < N; i++) {
			cin >> cmp;
			for (int j = 1; j < cmp; j++)
				if (!check[j])
					cnt += arr[N - i - 1];
			check[cmp] = true;
		}
		cout << cnt + 1 << endl;
	}

	return 0;
}