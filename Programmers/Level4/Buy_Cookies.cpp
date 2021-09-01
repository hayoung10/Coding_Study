#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;

    for (int m = 0; m < cookie.size() - 1; m++) {
        int lsum = cookie[m];
        int rsum = cookie[m + 1];
        int l = m;
        int r = m + 1;

        while (true) {
            if (lsum == rsum) {
                answer = max(answer, lsum);
            }
            if (lsum < rsum) {
                if (l == 0) break;
                lsum += cookie[--l];
            } else {
                if (r == cookie.size() - 1) break;
                rsum += cookie[++r];
            }
        }
    }

    return answer;
}

int main()
{
    cout << "cookie \t\tresult" << endl;
    cout << "[1,1,2,3] \t" << solution({ 1,1,2,3 }) << endl;
    cout << "[1,2,4,5] \t" << solution({ 1,2,4,5 }) << endl;

    return 0;
}