#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k, s;
	int map[402][402] = { 0, };
	cin >> n >> k;

	int before, after;
	for (int i = 0; i < k; i++) {
		cin >> before >> after;
		map[before][after] = -1;
		map[after][before] = 1;
	}

	// floyd-warshall
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] == 0) {
					if (map[j][i] == -1 && map[i][k] == -1) map[j][k] = -1;
					else if (map[j][i] == 1 && map[i][k] == 1) map[j][k] = 1;
				}
			}
		}
	}

	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> before >> after;
		cout << map[before][after] << "\n";
	}

	return 0;
}