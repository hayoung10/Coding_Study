#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<vector<bool>> visitedh; // ������ ��
vector<vector<bool>> visitedv; // ������ ��
int last = 0;

struct Robot {
    int x1, y1;
    int x2, y2;
    bool type; // true : ����, false : ����
    int time; // �ð�

    Robot(int a, int b, int c, int d, bool tp, int t) : x1(a), y1(b), x2(c), y2(d), type(tp), time(t) {}
};

bool check(Robot& loc) {
    if (map[loc.x1][loc.y1] == 1 || map[loc.x2][loc.y2] == 1)
        return false;

    loc.time++;
    if (loc.type == 0 && !visitedh[loc.x1][loc.y1]) // ������ �� �湮 Ȯ��
        visitedh[loc.x1][loc.y1] = true;
    else if (loc.type == 1 && !visitedv[loc.x1][loc.y1]) // ������ �� �湮 Ȯ��
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

        if (loc.x2 == last && loc.y2 == last) return loc.time; // ����

        if (loc.type) { // �κ��� ���η� ��ġ�ϸ�
            if (0 < loc.y1) { // �������� �̵�
                Robot temp = loc;
                temp.y1--; temp.y2--;
                if (check(temp)) q.push(temp);
            }
            if (0 < loc.x1) { // ���� �̵�
                Robot temp = loc;
                temp.x1--; temp.x2--;
                if (check(temp)) q.push(temp);

                if (map[loc.x1 - 1][loc.y1] == 0 && map[loc.x2 - 1][loc.y2] == 0) {
                    Robot temp2 = loc; // �������� ������ ���� ȸ��
                    temp2.x1--; temp2.y1++; temp2.type = false; // ����
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // ������ ������ ���� ȸ��
                    temp3.y1--; temp3.y2--; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            } 
            if (loc.x1 < last) { // �Ʒ��� �̵�
                Robot temp = loc;
                temp.x1++; temp.x2++;
                if (check(temp)) q.push(temp);
                
                if (map[loc.x1 + 1][loc.y1] == 0 && map[loc.x2 + 1][loc.y2] == 0) {
                    Robot temp2 = loc; // ������ ������ �Ʒ��� ȸ��
                    temp2.x2++; temp2.y2--; temp2.type = false; // ����
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // �������� ������ �Ʒ��� ȸ��
                    temp3.y1++; temp3.y2++; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.y2 < last) { // ���������� �̵�
                Robot temp = loc;
                temp.y1++; temp.y2++;
                if (check(temp)) q.push(temp);
            }
        }
        else { // �κ��� ���η� ��ġ�ϸ�
            if (0 < loc.x1) { // ���� �̵�
                Robot temp = loc;
                temp.x1--; temp.x2--;
                if (check(temp)) q.push(temp);
            }
            if (0 < loc.y1) { // �������� �̵�
                Robot temp = loc;
                temp.y1--; temp.y2--;
                if (check(temp)) q.push(temp);

                if (map[loc.x1][loc.y1 - 1] == 0 && map[loc.x2][loc.y2 - 1] == 0) {
                    Robot temp2 = loc; // �Ʒ��� ������ �������� ȸ��
                    temp2.x1++; temp2.y1--; temp2.type = true; // ����
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // ���� ������ �������� ȸ��
                    temp3.x1--; temp3.x2--; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.y1 < last) { // ���������� �̵�
                Robot temp = loc;
                temp.y1++; temp.y2++;
                if (check(temp)) q.push(temp);

                if (map[loc.x1][loc.y1 + 1] == 0 && map[loc.x2][loc.y2 + 1] == 0) {
                    Robot temp2 = loc; // ���� ������ ���������� ȸ��
                    temp2.x2--; temp2.y2++; temp2.type = true; // ����
                    if (check(temp2)) q.push(temp2);

                    Robot temp3 = temp2; // �Ʒ��� ������ ���������� ȸ��
                    temp3.x1++; temp3.x2++; temp3.time = loc.time;
                    if (check(temp3)) q.push(temp3);
                }
            }
            if (loc.x2 < last) { // �Ʒ��� �̵�
                Robot temp = loc;
                temp.x1++; temp.x2++;
                if (check(temp)) q.push(temp);
            }
        }
    }

    return -1; // ���� ��
}

int solution(vector<vector<int>> board) {
    //int answer = 0;
    map = board;
    last = board.size() - 1;

    Robot start(0, 0, 0, 1, true, 0); // (0,0),(0,1),����,�ð�:0
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