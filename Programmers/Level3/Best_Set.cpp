#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) {
        answer.push_back(-1);
    } else {
        int quot = s / n; // ¸ò
        int rem = s % n; // ³ª¸ÓÁö

        for (int i = 0; i < n; i++)
            answer.push_back(quot);
        for (int i = 1; i <= rem; i++)
            answer[answer.size() - i]++;
    }

    return answer;
}

int main()
{
    cout << "n \ts \tresult" << endl;

    cout << "2 \t9 \t[";
    vector<int> ans1 = solution(2, 9);
    if (ans1.size() != 1) {
        for (int i = 0; i < ans1.size() - 1; i++)
            cout << ans1[i] << ",";
        cout << ans1[ans1.size() - 1] << "]" << endl;
    } else cout << ans1[0] << "]" << endl;

    cout << "2 \t1 \t[";
    vector<int> ans2 = solution(2, 1);
    if (ans2.size() != 1) {
        for (int i = 0; i < ans2.size() - 1; i++)
            cout << ans2[i] << ",";
        cout << ans2[ans2.size() - 1] << "]" << endl;
    } else cout << ans2[0] << "]" << endl;

    cout << "2 \t8 \t[";
    vector<int> ans3 = solution(2, 8);
    if (ans3.size() != 1) {
        for (int i = 0; i < ans3.size() - 1; i++)
            cout << ans3[i] << ",";
        cout << ans3[ans3.size() - 1] << "]" << endl;
    } else cout << ans3[0] << "]" << endl;

    return 0;
}