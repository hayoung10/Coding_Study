#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool DFS(int n, vector<vector<int>>& computers)
{
    if (computers[n][n] == 0)
        return false;
    
    computers[n][n] = 0;
    for (int i = 0; i < computers.size(); i++)
        if (computers[n][i] == 1)
            DFS(i, computers);
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < computers.size(); i++) {
        if (computers[i][i] == 1)
            if (DFS(i, computers))
                answer++;
    }

    return answer;
}

int main()
{
    cout << "n \tcomputers \treturn" << endl;
    
    int ans1 = solution(3, { {1,1,0},{1,1,0},{0,0,1} });
    cout << "3 \t[[1,1,0],[1,1,0],[0,0,1]] \t" << ans1 << endl;

    int ans2 = solution(3, { {1, 1, 0},{1, 1, 1},{0, 1, 1} });
    cout << "3 \t[[1,1,0],[1,1,1],[0,1,1]] \t" << ans2 << endl;

    return 0;
}