#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;

bool dfs(string start, vector<vector<string>> tickets, vector<string>& answer ,int used) {
    answer.push_back(start);
    if (tickets.size() == used)
        return true;

    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && !visited[i]) {
            visited[i] = true;
            if (dfs(tickets[i][1], tickets, answer, used + 1))
                return true; // 올바른 경로이므로 즉시 리턴
            visited[i] = false;
        }
    }
    answer.pop_back(); // 옳지 않음 경로이므로 제거
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end());
    visited = vector<bool>(tickets.size(), false);

    dfs("ICN", tickets, answer, 0);

    return answer;
}

int main()
{
    cout << "tickets \t\t\t\t\treturn" << endl;
    cout << "[[\"ICN\",\"JFK\"],[\"HND\",\"IAD\"],[\"JFK\",\"HND\"]] \t[";

    vector<string> ans = solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
    for (int i = 0; i < ans.size() - 1; i++)
        cout << "\"" << ans[i] << "\",";
    cout << "\"" << ans[ans.size() - 1] << "\"]" << endl;

    return 0;
}