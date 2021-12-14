#include <iostream>
#include <algorithm> // sort, abs
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int left = 0, right = N - 1;
	int s1, s2;
	int minsum = 2000000000;
	while (left < right) {
		int sum = v[left] + v[right];

		if (minsum > abs(sum)) {
			minsum = abs(sum);
			s1 = v[left]; s2 = v[right];

			if (sum == 0) break;
		}
		if (sum < 0)
			left++;
		else
			right--;
	}
	cout << s1 << " " << s2 << endl;

	return 0;
}