#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> v[8];
bool user_visited[8]; // 초기화 값 : false
set<string> result;

void dfs(int deep, int size) {
    if (deep == size) {
        string ans = "";
        for (int i = 0; i < 8; i++)
            if (user_visited[i]) ans += to_string(i);
        result.insert(ans);
        return;
    }

    for (int i = 0; i < v[deep].size(); i++) {
        int user = v[deep][i];
        if (!user_visited[user]) {
            user_visited[user] = true;
            dfs(deep + 1, size);
            user_visited[user] = false; // dfs를 빠져나오면 다시 리셋
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < banned_id.size(); i++) {
        for (int j = 0; j < user_id.size(); j++) {
            if (banned_id[i].size() == user_id[j].size()) {
                bool check = true;
                for (int k = 0; k < banned_id[i].size(); k++) {
                    if (banned_id[i][k] != '*' && banned_id[i][k] != user_id[j][k]) {
                        check = false;
                        break;
                    }
                }
                if (check) v[i].push_back(j);
            }
        }
    }

    dfs(0, banned_id.size());

    return result.size();
}

int main()
{
    cout << "user_id \t\t\t\t\t\tbanned_id \t\tresult" << endl;

    cout << "[\"frodo\", \"fradi\", \"crodo\", \"abc123\", \"frodoc\"] \t[\"fr*d*\", \"abc1**\"] \t";
    cout << solution({ "frodo","fradi","crodo","abc123","frodoc" }, { "fr*d*","abc1**" }) << endl;

    return 0;
}