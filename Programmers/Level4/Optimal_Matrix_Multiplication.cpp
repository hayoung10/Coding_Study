#include <iostream>
#include <algorithm> // min
#include <string>
#include <vector>
using namespace std;

#define MAX_SIZE 200
#define MAX_VALUE 9223372036854775807

long long DP[MAX_SIZE][MAX_SIZE];
long long C[MAX_SIZE];

long long solution(vector<vector<int>> matrix_sizes) {
    int num = matrix_sizes.size() + 1;

    DP[0][0] = 0;
    C[0] = matrix_sizes[0][0];
    for (int i = 1; i < num; i++) {
        DP[i][i] = 0;
        C[i] = matrix_sizes[i - 1][1];
    }

    for (int dig = 0; dig < num; dig++) {
        for (int i = 1; i <= num - dig; i++) {
            int j = i + dig;
            if (i == j) continue;

            DP[i][j] = MAX_VALUE;
            for (int k = i; k < j; k++)
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k + 1][j] + C[i - 1] * C[k] * C[j]);
        }
    }

    return DP[1][num - 1];
}

int main()
{
    cout << "matrix_sizes \t\tresult" << endl;
    cout << "[[5,3],[3,10],[10,6]] \t" << solution({ {5,3},{3,10},{10,6} }) << endl;

	return 0;
}