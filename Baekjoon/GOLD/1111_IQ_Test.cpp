#include <iostream>
using namespace std;

int main()
{
	int N, arr[50];

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (N == 1) {
		cout << "A" << endl; return 0;
	} else if (N == 2) {
		if (arr[0] != arr[1])
			cout << "A" << endl;
		else
			cout << arr[0] << endl;
		return 0;
	} else {
		int a = 0;
		if (arr[0] != arr[1]) a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
		int b = arr[1] - arr[0] * a;
		for (int i = 2; i < N; i++) {
			if (arr[i] != arr[i - 1] * a + b) {
				cout << "B" << endl; return 0;
			}
		}
		cout << arr[N - 1] * a + b << endl;
	}

	return 0;
}