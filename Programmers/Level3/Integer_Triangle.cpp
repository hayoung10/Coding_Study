#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

vector<vector<int>> triangle2;

void dfs(int floor)
{
    if (floor == triangle2.size())
        return;

    for (int i = 0; i < triangle2[floor].size(); i++) {
        if (i == 0) {
            triangle2[floor][i] += triangle2[floor - 1][i];
        }
        else if (i == triangle2[floor].size() - 1) {
            triangle2[floor][i] += triangle2[floor - 1][i - 1];
        }
        else {
            triangle2[floor][i] += max(triangle2[floor - 1][i - 1], triangle2[floor - 1][i]);
        }
    }
    dfs(floor + 1);
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    triangle2 = triangle;
    dfs(1);

    for (int i = 0; i < triangle2.size(); i++)
        answer = max(answer, triangle2[triangle2.size() - 1][i]);

    return answer;
}

int main()
{
    vector<vector<int>> vec = { {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };

    int ans = solution(vec);
    cout << "answer : " << ans << endl;

    return 0;
}