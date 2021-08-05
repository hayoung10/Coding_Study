#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> rooms; // 배정할 수 있는 다음 방을 안내하기

long long findempty(long long roomNum) { // 비어있는 방 찾기
    if (!rooms.count(roomNum)) return roomNum;
    return rooms[roomNum] = findempty(rooms[roomNum]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (long long num : room_number) {
        long long roomNum = findempty(num);
        answer.push_back(roomNum);
        rooms[roomNum] = roomNum + 1; // roomNum의 다음 방으로 안내하기
    }

    return answer;
}

int main()
{
    cout << "k \troom_number \tresult" << endl;

    cout << "10 \t[1,3,4,1,3,1] \t[";
    vector<long long> ans = solution(10, { 1,3,4,1,3,1 });
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ",";
    cout << ans[ans.size() - 1] << "]" << endl;

    return 0;
}