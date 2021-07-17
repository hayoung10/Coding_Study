#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> v(n, vector<int>(m));

    for (int i = 0; i < puddles.size(); i++)
        v[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

    v[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] < 0) {
                v[i][j] = 0;
                continue;
            }
            if (i > 0)
                v[i][j] += v[i - 1][j] % 1000000007;
            if (j > 0)
                v[i][j] += v[i][j - 1] % 1000000007;
        }
    }

    return v[n - 1][m - 1] % 1000000007;
}

int main()
{
    cout << "m \tn \tpuddles \treturn" << endl;

    int ans1 = solution(4, 3, { { 2,2 } });
    cout << "4 \t3 \t[[2,2]] \t" << ans1 << endl;

    int ans2 = solution(3, 3, { {2,2} });
    cout << "3 \t3 \t[[2,2]] \t" << ans2 << endl;

    return 0;
}