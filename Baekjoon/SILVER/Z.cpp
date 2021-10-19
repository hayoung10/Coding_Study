#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

int findLocation(int num) {
	int square = num * num;

	if (r <= num) {
		if (c <= num) { // 4구역 중 1번째
			square *= 0;
		} else { // 4구역 중 2번째
			square *= 1;
			c -= num;
		}
	} else {
		if (c <= num) { // 4구역 중 3번째
			square *= 2;
			r -= num;
		} else { // 4구역 중 4번째
			square *= 3;
			r -= num;
			c -= num;
		}
	}

	return square;
}

int main()
{
	cin >> N >> r >> c;
	r++; c++;

	int total = 0;
	int num = pow(2, N - 1);
	while (num != 1) {
		total += findLocation(num);
		num /= 2;
	}
	total += findLocation(1);
	cout << total << endl;

	return 0;
}