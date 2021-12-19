#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll X, K;
	cin >> X >> K;

	ll Y = 0;
	int x_mask = 0;
	int k_mask = 0;

	while (true) {
		if (!((X >> x_mask) & 1)) {
			Y |= ((K >> k_mask) & 1) << x_mask;
			k_mask++;
			if (!(K >> k_mask)) break; // K == 0
		}
		x_mask++;
	}

	cout << Y << endl;

	return 0;
}