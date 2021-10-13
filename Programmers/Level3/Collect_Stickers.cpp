#include <iostream>
#include <algorithm> // max
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    vector<int> DP1(sticker.size(), 0); // 첫 번째 스티커를 선택했을 경우
    vector<int> DP2(sticker.size(), 0); // 첫 번째 스티커를 선택하지 않았을 경우

    if (sticker.size() == 1) return sticker[0];

    DP1[0] = DP1[1] = sticker[0];
    DP2[0] = 0; DP2[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++) {
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + sticker[i]);
        if (i == sticker.size() - 1) continue;
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + sticker[i]);
    }
    answer = max(DP1[sticker.size() - 2], DP2[sticker.size() - 1]);

    return answer;
}

int main()
{
    cout << "sticker \t\tanswer" << endl;
    cout << "[14,6,5,11,3,9,2,10] \t" << solution({ 14,6,5,11,3,9,2,10 }) << endl;
    cout << "[1,3,2,5,4] \t\t" << solution({ 1,3,2,5,4 }) << endl;

    return 0;
}