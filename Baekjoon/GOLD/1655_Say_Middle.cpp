#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> big_min;
priority_queue<int, vector<int>, less<int>> small_max;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (big_min.size() == small_max.size()) small_max.push(num);
		else big_min.push(num);

		if (!big_min.empty() && !small_max.empty() && big_min.top() < small_max.top()) {
			// swap
			int min_val = big_min.top();
			int max_val = small_max.top();
			big_min.pop(); small_max.pop();
			small_max.push(min_val);
			big_min.push(max_val);
		}
		cout << small_max.top() << '\n';
	}

	return 0;
}