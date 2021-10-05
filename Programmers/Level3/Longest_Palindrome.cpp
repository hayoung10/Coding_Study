#include <iostream>
#include <algorithm> // max
#include <string>
using namespace std;

int isPalindrome(string s, int left, int right) { // 팰린드롬인지 검사
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

    for (int i = 0; i < s.size(); i++) { // i : 팰린드롬을 비교할 기준
        int odd = isPalindrome(s, i, i); // 팰린드롬 길이가 홀수일 경우
        int even = isPalindrome(s, i - 1, i); // 팰린드롬 길이가 짝수일 경우
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