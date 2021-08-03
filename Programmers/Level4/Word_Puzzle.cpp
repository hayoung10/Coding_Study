#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dp[20000];

int solution(vector<string> strs, string t)
{
    for (int i = 0; i < t.size(); i++) {
        dp[i] = t.size() + 1;

        for (int j = 0; j < strs.size(); j++) {
            int last = strs[j].size() - 1;
            if (t[i] == strs[j][last] && last <= i) {
                if (t.substr(i - last, last + 1) == strs[j]) {
                    if (last == i)
                        dp[i] = 1;
                    else
                        dp[i] = min(dp[i - last - 1] + 1, dp[i]);
                }
            }
        }
    }

    if (dp[t.size() - 1] >= t.size() + 1)
        return -1;

    return dp[t.size() - 1];
}

int main()
{
    cout << "strs \t\t\tt \t\tresult" << endl;

    cout << "[\"ba\",\"na\",\"n\",\"a\"] \t\"banana\" \t";
    cout << solution({ "ba","na","n","a" }, "banana") << endl;

	return 0;
}