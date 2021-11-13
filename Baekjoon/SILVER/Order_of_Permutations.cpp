#include <iostream>
#include <algorithm> // next_permuttion
using namespace std;

int N, Q, k; // Q : question number
int arr[21];
int ans[21];
bool check[21];

int main()
{
	cin >> N;
	arr[0] = 1;
	for (int i = 1; i <= 20; i++)
		arr[i] = arr[i - 1] * i;

	cin >> Q;
	if (Q == 1) {
		cin >> k;
		for (int i = 0; i < N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[j]) continue;
				if (arr[N - i - 1] < k) {
					k -= arr[N - i - 1];
				} else {
					ans[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		for (int i = 0; i < N; i++)
			cout << ans[i] << " ";
		cout << endl;
	} else if (Q == 2) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> k;
			for (int j = 1; j < k; j++)
				if (!check[j])
					cnt += arr[N - i - 1];
			check[k] = true;
		}
		cnt++;
		cout << cnt << endl;
	}

	return 0;
}