#include <iostream>
#include <algorithm> // sort
#include <vector>
#include <queue> // priority_queue
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>> jewel(N);
	vector<int> bag(K);
	for (int i = 0; i < N; i++)
		cin >> jewel[i].first >> jewel[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	int idx = 0;
	long long ans = 0;
	priority_queue<int> pq;
	for (int i = 0; i < K; i++) {
		while (idx < N && jewel[idx].first <= bag[i])
			pq.push(jewel[idx++].second);

		if (!pq.empty()) {
			ans += (long long)pq.top();
			pq.pop();
		}
	}

	cout << ans << endl;

	return 0;
}