#include <iostream>
#include <algorithm> // sort
#include <queue> // priority_queue
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end());
    priority_queue<int, vector<int>, greater<int>> pq(B.begin(), B.end());

    int index = 0;
    
    while (!pq.empty()) {
        if (index == A.size()) break;

        int num = pq.top();
        pq.pop();
        if (A[index] < num) {
            index++;
            answer++;
        }
    }

    return answer;
}

int main()
{
    cout << "A \t\tB \t\tresult" << endl;
    cout << "[5,1,3,7] \t[2,2,6,8] \t" << solution({ 5,1,3,7 }, { 2,2,6,8 }) << endl;
    cout << "[2,2,2,2] \t[1,1,1,1] \t" << solution({ 2,2,2,2 }, { 1,1,1,1 }) << endl;

    return 0;
}