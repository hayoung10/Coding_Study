#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1]; // ascending
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int i = 0; // index
    int time = 0;

    while (i < jobs.size() || !pq.empty()) {
        if (i < jobs.size() && jobs[i][0] <= time) {
            pq.push(jobs[i++]);
            continue;
        }

        if (!pq.empty()) {
            time += pq.top()[1]; // + 작업의 소요시간
            answer += (time - pq.top()[0]); // + 작업의 요청부터 종료까지 걸린 시간
            pq.pop();
        }
        else {
            time = jobs[i][0];
        }
    }
    return answer / jobs.size(); // 소수점 이하의 수 버림
}

int main()
{
    cout << "jobs \t\t\t\t\treturn" << endl;
    cout << "[[0,3],[1,9],[2,6]] \t\t\t" << solution({ {0,3},{1,9},{2,6} }) << endl;
    cout << "[[0,3],[1,9],[500,6]] \t\t\t" << solution({ {0,3},{1,9},{500,6} }) << endl;
    cout << "[[0,3],[4,4],[5,3],[4,1]] \t\t" << solution({ {0,3},{4,4},{5,3},{4,1} }) << endl;
    cout << "[[1,9],[1,4],[1,5],[1,7],[1,3]] \t" << solution({ {1,9},{1,4},{1,5},{1,7},{1,3} }) << endl;
    cout << "[[0,9],[0,4],[0,5],[0,7],[0,3]] \t" << solution({ {0,9},{0,4},{0,5},{0,7},{0,3} }) << endl;

    return 0;
}