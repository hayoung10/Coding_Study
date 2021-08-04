#include <iostream>
#include <vector>
using namespace std;

int dp1[1000000]; // 첫 번째 집을 선택한 경우
int dp2[1000000]; // 두 번째 집부터 선택한 경우

int solution(vector<int> money) {
    int answer = 0;

    dp1[0] = money[0];
    dp1[1] = money[0]; // 두 번째 집을 선택하지 못하므로

    dp2[0] = 0; // 첫 번째 집을 선택하지 않으므로
    dp2[1] = money[1];

    int len = money.size();
    for (int i = 2; i < len - 1; i++) {
        dp1[i] = max(dp1[i - 2] + money[i], dp1[i - 1]);
        dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
    }

    dp2[len - 1] = max(dp2[len - 3] + money[len - 1], dp2[len - 2]);

    return max(dp1[len - 2], dp2[len - 1]);
}

int main()
{
    cout << "money \t\treturn" << endl;
    cout << "[1,2,3,1] \t" << solution({ 1,2,3,1 }) << endl;

    return 0;
}