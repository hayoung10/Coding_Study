#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());

    int end = routes[0][1];
    for (int i = 0; i < routes.size(); i++) {
        if (end < routes[i][0]) {
            end = routes[i][1];
            answer++; // 카메라 설치
        }

        if (end > routes[i][1]) // 기준보다 먼저 나가는 차량이 있을 경우
            end = routes[i][1];
    }

    return answer;
}

int main()
{
    cout << "routes \t\t\t\t\treturn" << endl;
    cout << "[[-20,15],[-14,-5],[-18,-13],[-5,-3]] \t" << solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} }) << endl;

    return 0;
}