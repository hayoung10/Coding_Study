#include <iostream>
#include <algorithm> // next_permutation, min
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> gboard; // game board
vector<int> card;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 12345679;
int cur_r, cur_c; // cursor

int bfs(int num) {
    bool visited[4][4] = { 0, };
    queue<pair<pair<int, int>, int>> q;
    q.push({ {cur_r,cur_c},0 });
    visited[cur_r][cur_c] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if (gboard[x][y] == num) {
            gboard[x][y] = 0;
            cur_r = x, cur_c = y;
            return cnt + 1; // + Enter
        }
        for (int i = 0; i < 4; i++) { // ก็, ก่, ก้, กๆ
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx>3 || ny>3) continue;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx,ny},cnt + 1 });
            }
        }
        for (int i = 0; i < 4; i++) { // [Ctrl] + ก็, ก่, ก้, กๆ
            int nx = x;
            int ny = y;
            while (0 <= nx + dx[i] && nx + dx[i] < 4 && 0 <= ny + dy[i] && ny + dy[i] < 4) {
                nx += dx[i];
                ny += dy[i];
                if (gboard[nx][ny]) break;
            }
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ {nx,ny},cnt + 1 });
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    bool card_check[7] = { 0, }; // card number : 1~6
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j]) card_check[board[i][j]] = true;

    for (int i = 1; i < 7; i++)
        if (card_check[i]) card.push_back(i);

    do {
        gboard = board;
        cur_r = r, cur_c = c;
        int tmp = 0;
        for (int i = 0; i < card.size(); i++) { // a pair of two cards
            tmp += bfs(card[i]);
            tmp += bfs(card[i]);
        }
        answer = min(answer, tmp);
        
    } while (next_permutation(card.begin(), card.end()));

    return answer;
}

int main()
{
    cout << "board\t\t\t\t\t\t r\t c\t result" << endl;
    cout << "[[1,0,0,3],[2,0,0,0],[0,0,0,2],[3,0,1,0]]\t 1\t 0\t ";
    cout << solution({ {1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0} }, 1, 0) << endl;

	return 0;
}