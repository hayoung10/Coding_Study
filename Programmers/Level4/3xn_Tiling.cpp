#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
    if (n % 2 == 1) return 0;
    
    long long DP[2500] = { 0, }; // 0으로 초기화
    DP[0] = 1;
    DP[1] = 3; // n = 2

    int n2 = n / 2;
    for (int i = 2; i <= n2; i++) {
        DP[i] = DP[i - 1] * 3;
        for (int j = 0; j < i - 1; j++)
            DP[i] += DP[j] * 2;
        DP[i] %= 1000000007;
    }

    return (int)DP[n2];
}

int main()
{
    cout << "n \tresult" << endl;
    cout << "4 \t" << solution(4) << endl;
    return 0;
}