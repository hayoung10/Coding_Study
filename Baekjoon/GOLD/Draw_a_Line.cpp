#include <iostream>
#include <algorithm> // sort, pair
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> lines;
int a, b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		lines.push_back({ a,b });
	}
	sort(lines.begin(), lines.end());

	int ans = 0;
	int start = lines[0].first;
	int end = lines[0].second;
	for (int i = 1; i < N; i++) {
		if (lines[i].first <= end) {
			if (end < lines[i].second)
				end = lines[i].second;
		} else {
			ans += (end - start);
			start = lines[i].first;
			end = lines[i].second;
		}
	}
	ans += (end - start);
	cout << ans << endl;

	return 0;
}