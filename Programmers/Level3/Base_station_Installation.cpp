#include <iostream>
#include <vector>
using namespace std;

int number(int space, int gap) {
    if (space > 0) {
        int quotient = (int)(space / gap);
        if (space % gap > 0) quotient++;
        return quotient; // 증설해야 하는 기지국 개수
    }
    return 0; // 증설 안 함
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int gap = 2 * w + 1;
    int space = stations[0] - w - 1;
    answer += number(space, gap);

    for (int i = 1; i < stations.size(); i++) {
        space = stations[i] - stations[i - 1] - gap;
        answer += number(space, gap);
    }
    space = n - stations[stations.size() - 1] - w;
    answer += number(space, gap);

    return answer;
}

int main()
{
    cout << "N \tstations \tW \tanswer" << endl;
    cout << "11 \t[4,11] \t\t1 \t" << solution(11, { 4,11 }, 1) << endl;
    cout << "16 \t[9] \t\t2 \t" << solution(16, { 9 }, 2) << endl;

    return 0;
}