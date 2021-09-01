#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> paren;

    for (int i = 0; i < n; i++)
        paren.insert(paren.end(), { 1,-1 }); // ( : 1, ) : -1

    do {
        int sum = 0;
        answer++;
        for (int i = 0; i < 2 * n; i++) {
            sum += paren[i];
            if (sum < 0) { // °ýÈ£½ÖÀÌ ¸ÂÁö ¾Ê´Â °æ¿ì
                answer--;
                break;
            }
        }
    } while (next_permutation(paren.begin(), paren.end()));

    return answer;
}

int main()
{
    cout << "n \tresult" << endl;
    cout << "2 \t" << solution(2) << endl;
    cout << "3 \t" << solution(3) << endl;

    return 0;
}