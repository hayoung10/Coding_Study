#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    map<string, int> type;
    for (int i = 0; i < gems.size(); i++)
        type[gems[i]]++;
    int total = type.size();
    int dis = gems.size() + 1; // 가장 작은 구간이 진열대의 전체 길이일 경우를 대비하여 +1
    int start = 0, end = 0; // index

    type.clear();
    while (true) { // 짧은 구간 찾기
        if (type.size() == total) {
            if (end - start < dis) {
                answer = { start + 1, end }; // end는 후위연산자로 인해 +1을 하지 않음
                dis = end - start;
            }

            if (type[gems[start]] > 1)
                type[gems[start]]--;
            else
                type.erase(gems[start]);
            start++;
        }
        else if (end == gems.size()) {
            break;
        }
        else if (type.size() < total) {
            type[gems[end++]]++;
        }
    }

    return answer;
}

int main() {
    cout << "gems => result" << endl;

    vector<int> ans1 = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    cout << "[\"DIA\", \"RUBY\", \"RUBY\", \"DIA\", \"DIA\", \"EMERALD\", \"SAPPHIRE\", \"DIA\"] => [" << ans1[0] << ", " << ans1[1] << "]" << endl;

    vector<int> ans2 = solution({ "AA", "AB", "AC", "AA", "AC" });
    cout << "[\"AA\", \"AB\", \"AC\", \"AA\", \"AC\"] => [" << ans2[0] << ", " << ans2[1] << "]" << endl;

    vector<int> ans3 = solution({ "XYZ", "XYZ", "XYZ" });
    cout << "[\"XYZ\", \"XYZ\", \"XYZ\"] => [" << ans3[0] << ", " << ans3[1] << "]" << endl;

    vector<int> ans4 = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
    cout << "[\"ZZZ\", \"YYY\", \"NNNN\", \"YYY\", \"BBB\"] => [" << ans4[0] << ", " << ans4[1] << "]" << endl;

    return 0;
}