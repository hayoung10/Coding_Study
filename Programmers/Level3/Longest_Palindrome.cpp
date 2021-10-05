#include <iostream>
#include <algorithm> // max
#include <string>
using namespace std;

int isPalindrome(string s, int left, int right) { // �Ӹ�������� �˻�
    while (0 <= left && right <= s.size() - 1) {
        if (s[left] != s[right]) break;
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++) { // i : �Ӹ������ ���� ����
        int odd = isPalindrome(s, i, i); // �Ӹ���� ���̰� Ȧ���� ���
        int even = isPalindrome(s, i - 1, i); // �Ӹ���� ���̰� ¦���� ���
        answer = max(answer, max(odd, even));
    }

    return answer;
}

int main()
{
    cout << "s \t\tanswer" << endl;
    cout << "abcdcba \t" << solution("abcdcba") << endl;
    cout << "abacde \t\t" << solution("abacde") << endl;

    return 0;
}