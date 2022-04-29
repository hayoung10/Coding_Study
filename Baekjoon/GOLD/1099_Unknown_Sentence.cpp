#include <iostream>
#include <algorithm> // min
#include <cstring> // memset
#include <string>
#include <vector>
using namespace std;

#define INF 987654321

int N;
string sentence, nwords[51];
int cache[51], search_cache[51][51];

int search(int idx, int w_idx) {
	int& cnt = search_cache[idx][w_idx];
	if (cnt != -1) return cnt;

	string word = nwords[w_idx];
	if (idx + word.size() > sentence.size()) return cnt = INF;

	cnt = 0;
	vector<int> alphabet(26);
	for (int i = 0; i < word.size(); i++) {
		int word_c = word[i] - 'a';
		int sentence_c = sentence[idx + i] - 'a';

		alphabet[word_c]++;
		alphabet[sentence_c]--;
		if (word_c != sentence_c) cnt++;
	}

	for (int i = 0; i < 26; i++)
		if (alphabet[i]) return cnt = INF;

	return cnt;
}

int dp(int idx) {
	if (idx >= sentence.size()) return 0;

	int& ret = cache[idx];
	if (ret != -1) return ret;
	ret = INF;

	for (int i = 0; i < N; i++) {
		int cost = search(idx, i);
		if (cost != INF) ret = min(ret, cost + dp(idx + nwords[i].size()));
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> sentence;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> nwords[i];

	memset(cache, -1, sizeof(cache));
	memset(search_cache, -1, sizeof(search_cache));

	int ans = dp(0);
	if (ans != INF) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}