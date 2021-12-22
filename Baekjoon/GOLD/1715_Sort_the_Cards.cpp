#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int cards;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		cin >> cards;
		pq.push(cards);
	}

	if (pq.size() == 1) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	int a, b;
	while (pq.size() > 1) {
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}
	cout << ans << endl;

	return 0;
}