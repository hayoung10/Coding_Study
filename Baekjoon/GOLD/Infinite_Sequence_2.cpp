#include <iostream>
#include <map>
using namespace std;

long long N, P, Q, X, Y;
map<long long, long long> A;

long long func(long long num) {
	if (num <= 0) return 1;
	if (A.count(num))
		return A[num];
	else
		return A[num] = func(num / P - X) + func(num / Q - Y);
}

int main()
{
	cin >> N >> P >> Q >> X >> Y;

	cout << func(N) << endl;

	return 0;
}