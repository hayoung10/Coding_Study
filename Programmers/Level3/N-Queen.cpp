#include <iostream>
#include <vector>
#include <cmath> // abs
using namespace std;

int answer = 0;
int N = 0;
int queen[12] = { 0, };

bool checked(int num) {
    for (int i = 0; i < num; i++) {
        if (queen[i] == queen[num] || abs(queen[i]-queen[num]) == abs(i-num)) return false;
    }
    return true;
}

void dfs(int num)
{
    if (N == num) {
        answer++;
        return;
    }

    for (int i = 0; i < N; i++) {
        queen[num] = i;
        if (checked(num))
            dfs(num + 1);
        queen[num] = 0;
    }
    return;
}

int solution(int n) {
    N = n;
    dfs(0);

    return answer;
}

int main()
{
    cout << "n \tresult" << endl;
    cout << "4 \t" << solution(4) << endl;

    return 0;
}