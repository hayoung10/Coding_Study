#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end()); // 오름차순으로 정렬

    int left = 0, right = distance;
    while (left <= right) {
        int mid = (left + right) / 2; // 중간값
        int cmp = 0, count = 0; // cmp : 비교대상, count : 제거한 바위의 수

        for (int i = 0; i < rocks.size(); i++) {
            if (mid > rocks[i] - cmp) count++;
            else cmp = rocks[i];
        }
        if (count > n) { // 불가능
            right = mid - 1;
        }
        else { // 가능
            answer = max(mid, answer);
            left = mid + 1;
        }
    }

    return answer;
}

int main()
{
    cout << "distance \trocks \t\t\tn \treturn" << endl;
    
    cout << "25 \t\t[2,14,11,21,17] \t2 \t" << solution(25, { 2,14,11,21,17 }, 2) << endl;

    return 0;
}
