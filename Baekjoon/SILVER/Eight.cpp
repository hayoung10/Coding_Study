#include <iostream>
using namespace std;

int main()
{
	string L, W;
	cin >> L >> W;
	if (L.size() != W.size()) {
		cout << 0 << endl;
		return 0;
	}

	int cnt = 0;
	for (int i = 0; i < L.size(); i++) {
		if (L[i] == W[i] && L[i] == '8')
			cnt++;
		else if (L[i] != W[i])
			break;
	}
	cout << cnt << endl;

	return 0;
}