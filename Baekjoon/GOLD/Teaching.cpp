#include <iostream>
#include <algorithm> // max
#include <string>
using namespace std;

int N, K, answer;
string words[50];
bool visited[26] = { false, };

void learnAlphabet(int alpha, int cnt) {
	if (cnt == K - 5) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			bool check = true;
			for (int j = 0; j < words[i].size(); j++) {
				if (!visited[words[i][j] - 'a']) {
					check = false;
					break;
				}
			}
			if (check) temp++;
		}
		answer = max(answer, temp);
		return;
	}

	for (int m = alpha; m < 26; m++) {
		if (!visited[m]) {
			visited[m] = true;
			learnAlphabet(m, cnt + 1);
			visited[m] = false;
		}
	}
}

int main()
{
	cin >> N >> K;
	if (K < 5) {
		cout << 0 << endl;
		return 0;
	} else if (K == 26) { // All alphabet
		cout << N << endl;
		return 0;
	}

	for (int i = 0; i < N; i++) {
		cin >> words[i];
		words[i] = words[i].substr(4, words[i].size() - 8);
	}
	visited[0] = true; // 'a'
	visited['c' - 'a'] = true; // 'c
	visited['i' - 'a'] = true; // 'i'
	visited['n' - 'a'] = true; // 'n'
	visited['t' - 'a'] = true; // 't'

	learnAlphabet(0, 0);
	cout << answer << endl;
	return 0;
}