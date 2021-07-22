#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    // use Floyd Warshall Algorithm
    vector<vector<bool>> check(n, vector<bool>(n, false));
    for (int i = 0; i < results.size(); i++)
        check[results[i][0] - 1][results[i][1] - 1] = true; // win -> true

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (check[j][i] && check[i][k])
                    check[j][k] = true;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (check[i][j] || check[j][i]) // check the number of wins and losses
                count++;
        if (count == n - 1)
            answer++;
    }

    return answer;
}

int main()
{
    cout << "n \tresults \t\t\t\treturn" << endl;
    cout << "5 \t[[4,3],[4,2],[3,2],[1,2],[2,5]] \t" << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} }) << endl;

    return 0;
}