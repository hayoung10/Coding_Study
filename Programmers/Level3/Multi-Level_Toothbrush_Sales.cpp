#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, string> er; // enroll-referral
map<string, int> result; // enroll-result

void dfs(string name, int profit) {
    if (name == "-")
        return;

    int give = profit * 0.1;
    int get = profit - give;

    result[name] += get;
    if (give < 1)
        return;
    dfs(er[name], give);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++) { // mapping
        er[enroll[i]] = referral[i];
        result[enroll[i]] = 0; // 결과를 0으로 초기화
    }

    for (int i = 0; i < seller.size(); i++)
        dfs(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(result[enroll[i]]);

    return answer;
}

int main()
{
    cout << "enroll : [\"john\", \"mary\", \"edward\", \"sam\", \"emily\", \"jaimie\", \"tod\", \"young\"]"<<endl;
    cout << "referral : [\"-\", \"-\", \"mary\", \"edward\", \"mary\", \"mary\", \"jaimie\", \"edward\"]" << endl;
    cout << "seller : [\"young\", \"john\", \"tod\", \"emily\", \"mary\"]" << endl;
    cout << "amount : [12, 4, 2, 5, 10]" << endl;
    cout << "result : [";

    vector<int> result = solution({ "john","mary","edward","sam","emily","jaimie","tod","young" },
        { "-","-","mary","edward","mary","mary","jaimie","edward" }, { "young","john","tod","emily","mary" }, { 12,4,2,5,10 });

    for (int i = 0; i < result.size() - 1; i++)
        cout << result[i] << ", ";
    cout << result[result.size() - 1] << "]" << endl;

	return 0;
}