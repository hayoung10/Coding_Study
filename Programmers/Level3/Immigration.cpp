#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0, avgt = 0, people = 0, mint = 1;
    long long maxt = *max_element(times.begin(), times.end()) * (long long)n;

    while (mint <= maxt)
    {
        avgt = (mint + maxt) / 2;
        for (auto t : times)
            people += avgt / t;
        if (n <= people) {
            answer = avgt;
            maxt = avgt - 1;
        }
        else {
            mint = avgt + 1;
        }

        people = 0;
    }

    return answer;
}

int main()
{
    cout << "n \ttimes \treturn" << endl;
    cout << "6 \t[7,10] \t" << solution(6, { 7,10 }) << endl;

    return 0;
}