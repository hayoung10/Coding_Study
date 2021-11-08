#include <iostream>
#include <map>
using namespace std;

long long N, P, Q;
map<long long, long long> A;

long long func(long long num) {
	if (A.count(num))
		return A[num];
	else
		return A[num] = func(num / P) + func(num / Q);
}

int main()
{
	cin >> N >> P >> Q;

	A[0] = 1;
	cout << func(N) << endl;

	return 0;
}