#include <iostream>
#include <algorithm> // pair
#include <string>
#include <queue>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	queue<pair<string, int>> q;
	set<string> visited;
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	string s = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char c;
			cin >> c;
			s += c;
		}
	}
	q.push({ s,0 });
	visited.insert(s);

	int ans = -1;
	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == "123456780") {
			cout << cnt << endl;
			return 0;
		}

		int zero = cur.find('0');
		int x = zero / 3, y = zero % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			string next = cur;
			swap(next[x * 3 + y], next[nx * 3 + ny]);

			if (visited.find(next) == visited.end()) {
				visited.insert(next);
				q.push({ next, cnt + 1 });
			}
		}
	}
	cout << -1 << endl;

	return 0;
}