#include <iostream>
#include <algorithm> // sort, min
#include <vector>
using namespace std;

#define MAX_VALUE 9223372036854775807

long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = MAX_VALUE;
    vector<long long> blocks;
    long long total = 0; // 총 블럭 수
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            blocks.push_back(land[i][j]);
            total += land[i][j];
        }
    }
    sort(blocks.begin(), blocks.end());

    long long height = -1; // (높이가 0인 경우를 포함하기 위해)
    long long before_blocks = 0; // 인덱스 이전의 블럭 수
    for (int i = 0; i < blocks.size(); i++) {
        if (height != blocks[i]) {
            long long add = blocks[i] * i - before_blocks;
            long long remove = total - before_blocks - blocks[i] * (blocks.size() - i);
            long long costs = add * P + remove * Q;
            answer = min(answer, costs);
            height = blocks[i];
        }
        before_blocks += blocks[i];
    }

    return answer;
}

int main() {
    cout << "land \t\t\t\tP \tQ \tresult" << endl;
    cout << "[[1,2],[2,3]] \t\t\t3 \t2 \t" << solution({ {1,2},{2,3} }, 3, 2) << endl;
    cout << "[[4,4,3],[3,2,2],[2,1,0]] \t5 \t3 \t" << solution({ {4,4,3},{3,2,2},{2,1,0} }, 5, 3) << endl;

    return 0;
}