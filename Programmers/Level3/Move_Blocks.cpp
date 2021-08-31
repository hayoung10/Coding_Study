#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visitedh; // 가로일 때
vector<vector<bool>> visitedv; // 세로일 때
int last = 0;

struct Robot {
    int x1, y1;
    int x2, y2;
    bool type; // true : 가로, false : 세로
    int time; // 시간

    Robot(int a, int b, int c, int d, bool tp, int t) : x1(a), y1(b), x2(c), y2(d), type(tp), time(t) {}
};

bool check(Robot& loc) {
    if (map[loc.x1][loc.y1] == 1 || map[loc.x2][loc.y2] == 1)
        return false;

    loc.time++;
    if (loc.type == 0 && !visitedh[loc.x1][loc.y1]) // 가로일 때 방문 확인
        visitedh[loc.x1][loc.y1] = true;
    else if (loc.type == 1 && !visitedv[loc.x1][loc.y1]) // 세로일 때 방문 확인
        visitedv[loc.x1][loc.y1] = true;
    else
        return false;

    return true;
}

int bfs(Robot start) {
    queue<Robot> q;
    q.push(start);

    while (!q.empty()) {
        Robot loc = q.front();
        q.pop();

        if (loc.x2 == last && loc.y2 == last) return loc.time; // 도착

        if (loc.type) { // 로봇이 가로로 위치하면
            if (0 < loc.y1) { // 왼쪽으로 이동
                Robot temp = loc;
                temp.y1--; temp.y2--;
                if (check(temp)) q.push(temp);
            }
            if (0 < loc.x1) { // 위로 이동
                Robot temp = loc;
                temp.x1--; temp.x2--;
                if (check(temp)) q.push(temp);

                if (map[loc.x1 - 1][loc.y1] == 0 && map[loc.x2 - 1][loc.y2] == 0) {
                    Robot temp2 = loc; // 오른쪽을 축으로 위로 회전
                    temp2.x1--; temp2.y1++; temp2.type = false; // 세로
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // 왼쪽을 축으로 위로 회전
                    temp3.y1--; temp3.y2--; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            } 
            if (loc.x1 < last) { // 아래로 이동
                Robot temp = loc;
                temp.x1++; temp.x2++;
                if (check(temp)) q.push(temp);
                
                if (map[loc.x1 + 1][loc.y1] == 0 && map[loc.x2 + 1][loc.y2] == 0) {
                    Robot temp2 = loc; // 왼쪽을 축으로 아래로 회전
                    temp2.x2++; temp2.y2--; temp2.type = false; // 세로
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // 오른쪽을 축으로 아래로 회전
                    temp3.y1++; temp3.y2++; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.y2 < last) { // 오른쪽으로 이동
                Robot temp = loc;
                temp.y1++; temp.y2++;
                if (check(temp)) q.push(temp);
            }
        }
        else { // 로봇이 세로로 위치하면
            if (0 < loc.x1) { // 위로 이동
                Robot temp = loc;
                temp.x1--; temp.x2--;
                if (check(temp)) q.push(temp);
            }
            if (0 < loc.y1) { // 왼쪽으로 이동
                Robot temp = loc;
                temp.y1--; temp.y2--;
                if (check(temp)) q.push(temp);

                if (map[loc.x1][loc.y1 - 1] == 0 && map[loc.x2][loc.y2 - 1] == 0) {
                    Robot temp2 = loc; // 아래를 축으로 왼쪽으로 회전
                    temp2.x1++; temp2.y1--; temp2.type = true; // 가로
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // 위를 축으로 왼쪽으로 회전
                    temp3.x1--; temp3.x2--; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.y1 < last) { // 오른쪽으로 이동
                Robot temp = loc;
                temp.y1++; temp.y2++;
                if (check(temp)) q.push(temp);

                if (map[loc.x1][loc.y1 + 1] == 0 && map[loc.x2][loc.y2 + 1] == 0) {
                    Robot temp2 = loc; // 위를 축으로 오른쪽으로 회전
                    temp2.x2--; temp2.y2++; temp2.type = true; // 가로
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // 아래를 축으로 오른쪽으로 회전
                    temp3.x1++; temp3.x2++; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.x2 < last) { // 아래로 이동
                Robot temp = loc;
                temp.x1++; temp.x2++;
                if (check(temp)) q.push(temp);
            }
        }
    }

    return -1; // 실패 시
}

int solution(vector<vector<int>> board) {
    //int answer = 0;
    map = board;
    last = board.size() - 1;

    Robot start(0, 0, 0, 1, true, 0); // (0,0),(0,1),가로,시간:0
    visitedh = vector<vector<bool>>(last + 1, vector<bool>(last + 1, false));
    visitedv = vector<vector<bool>>(last + 1, vector<bool>(last + 1, false));
    int answer = bfs(start);

    return answer;
}

int main()
{
    cout << "board \t\t\t\t\t\t\t\t\t\t\tresult" << endl;
    cout << "[[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]] \t";
    cout << solution({ {0,0,0,1,1,},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0,0} }) << endl;

    return 0;
}