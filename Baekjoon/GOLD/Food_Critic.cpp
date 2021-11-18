#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;

	return gcd(b, a % b);
}

int main()
{
	int N, M;
	cin >> N >> M;

	int ans = gcd(N, M);
	cout << M - ans << endl;

	return 0;
}