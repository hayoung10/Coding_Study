#include <iostream>
#include <algorithm> // sort
#include <string>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew;
    for (int i = 0; i < timetable.size(); i++) {
        int c_hour = stoi(timetable[i].substr(0, 2));
        int c_min = stoi(timetable[i].substr(3, 2));
        int c_time = c_hour * 60 + c_min;
        crew.push_back(c_time);
    }
    sort(crew.begin(), crew.end());

    int start_time = 540; // 09:00
    int index = 0;
    int ans;
    for (int i = 1; i <= n; i++, start_time += t) {
        int cnt = 0;
        for (int j = index; j < crew.size(); j++) {
            if (crew[j] <= start_time) {
                index++;
                cnt++;
                if (cnt == m) break;
            }
        }
        if (i == n) {
            if (cnt == m) ans = crew[index - 1] - 1;
            else ans = start_time;
        }
    }

    string answer = "";
    int hour = ans / 60;
    if (hour < 10)
        answer ="0" + to_string(hour) + ":";
    else
        answer = to_string(hour) + ":";

    int min = ans % 60;
    if (min < 10)
        answer += "0" + to_string(min);
    else
        answer += to_string(min);

    return answer;
}

int main()
{
    cout << "n\t t\t m\t timetable\t\t\t\t answer" << endl;
    cout << "1 \t 1\t 5\t [\"08:00\", \"08:01\", \"08:02\", \"08:03\"]\t ";
    cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << endl;

	return 0;
}