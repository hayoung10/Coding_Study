#include <iostream>
#include <vector>
using namespace std;

int N;
int p[4] = { 2,3,5,7 };

bool is_prime(int num) {
	if (num == 0 || num == 1) return false;

	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	
	return true;
}

void make_num(int num, int len) {
	if (len == N) {
		cout << num << endl;
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		if (is_prime(num * 10 + i))
			make_num(num * 10 + i, len + 1);
	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < 4; i++)
		make_num(p[i], 1);

	return 0;
}