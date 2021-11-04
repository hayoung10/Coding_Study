#include <iostream>
#include <algorithm> // sort
#include <cmath> // pow
#include <vector>
#include <map>
using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
	return a.second > b.second;
}

int main()
{
	int N;
	cin >> N;

	string str;
	map<char, int> alpha;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int s = str.size();
		for (int j = 1; j <= s; j++) {
			alpha[str[j - 1]] += pow(10, (s - j));
		}
	}

	vector<pair<char, int>> v(alpha.begin(), alpha.end());
	sort(v.begin(), v.end(), cmp);

	int sum = 0;
	int num = 9;
	for (int i = 0; i < v.size(); i++) {
		sum += num * v[i].second;
		num--;
	}
	cout << sum << endl;

	return 0;
}