#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos {
    int x, y, dir, cost; // dir = direction
};

int solution(vector<vector<int>> board) {
    int answer = 0x7FFFFFFF; // 최대에서 시작
    
    int xdir[4] = { -1,0,0,1 };
    int ydir[4] = { 0,-1,1,0 };
    int N = board.size();

    queue<Pos> q;
    Pos start({ 0,0,-1,0 });
    q.push(start);

    while (!q.empty()) {
        Pos p = q.front();
        q.pop();

        if (p.x == N - 1 && p.y == N - 1) {
            answer = min(answer, p.cost);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int xx = p.x + xdir[i];
            int yy = p.y + ydir[i];

            if (0 <= xx && xx < N && 0 <= yy && yy < N) {
                if (board[xx][yy] == 1)
                    continue;

                int nCost; // next cost
                if (p.dir == -1 || p.dir == i)
                    nCost = p.cost + 100; // 같은 방향 (직선도로)
                else
                    nCost = p.cost + 100 + 500; // 다른 방향 (직선도로 + 코너)

                if (board[xx][yy] == 0 || board[xx][yy] >= nCost) {
                    board[xx][yy] = nCost;
                    q.push({ xx,yy,i,nCost });
                }
            }
        }
    }

    return answer;
}

int main()
{
    cout << "board \t\t\t\tresult" << endl;
    cout << "[[0,0,0],[0,0,0],[0,0,0]] \t" << solution({ {0,0,0},{0,0,0},{0,0,0} }) << endl;

    return 0;
}