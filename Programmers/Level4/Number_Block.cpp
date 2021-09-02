#include <iostream>
#include <vector>
#include <cmath> // sqrt
using namespace std;

vector<int> solution(long long begin, long long end) {
	vector<int> answer(end - begin + 1, 1);
	if (begin == 1) answer[0] = 0;

    for (int i = 0; i < answer.size(); i++) {
        int num = begin + i;
        int a = 2;
        while (a <= sqrt(num)) {
            if (num % a == 0) {
                int quotient = num / a;
                if (quotient <= 10000000) {
                    answer[i] = quotient;
                    break;
                }
            }
            a++;
        }
    }

	return answer;
}

int main()
{
    cout << "begin \tend \tresult" << endl;
    cout << "1 \t10 \t[";
    vector<int> ans = solution(1, 10);
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << ans[ans.size() - 1] << "]" << endl;

	return 0;
}