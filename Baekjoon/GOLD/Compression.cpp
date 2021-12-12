#include <iostream>
using namespace std;

string S;
bool visited[51] = { 0, };

int func1(int index) {
	int cnt = 0;

	for (int i = index; i < S.size(); i++) {
		if (visited[i]) continue;

		visited[i] = true;
		if (S[i] == '(') {
			int num = S[i - 1] - '0';
			cnt--;
			cnt += num * func1(i + 1);
		}
		else if (S[i] == ')') {
			return cnt;
		}
		else {
			cnt++;
		}
	}

	return cnt;
}

int main() {
	cin >> S;

	cout << func1(0) << endl;

	return 0;
}