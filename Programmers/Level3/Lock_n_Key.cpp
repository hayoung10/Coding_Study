#include <iostream>
#include <vector>
using namespace std;

int M, N, MN;

void rotate90(vector<vector<int>>& key) { // 시계방향으로 90도 회전
    vector<vector<int>> tmp(M, vector<int>(M));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            tmp[j][M - i - 1] = key[i][j];
    key = tmp;
}

bool check(int x, int y, vector<vector<int>> key, vector<vector<int>> lock2) {
    for (int i = x; i < x + M; i++)
        for (int j = y; j < y + M; j++)
            lock2[i][j] += key[i - x][j - y]; // lock2 위에 key 겹쳐놓기

    for (int i = M - 1; i < M + N - 1; i++) {
        for (int j = M - 1; j < M + N - 1; j++) {
            if (lock2[i][j] != 1) // lock2에서 중앙인 자물쇠 구간을 완벽하게 채우지 못한 경우
                return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    MN = 2 * M + N - 2;

    vector<vector<int>> lock2(MN, vector<int>(MN, 0)); // lock2 가운데에 lock 배치
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            lock2[i + M - 1][j + M - 1] = lock[i][j];

    for (int k = 0; k < 4; k++) { // 4번 회전
        for (int i = 0; i < M + N - 1; i++) {
            for (int j = 0; j < M + N - 1; j++) {
                if (check(i, j, key, lock2))
                    return true;
            }
        }
        rotate90(key);
    }

    return false;
}

int main()
{
    cout << "key \t\t\t\tlock \t\t\t\tresult" << endl;
    cout << "[[0,0,0,],[1,0,0],[0,1,1]] \t[[1,1,1],[1,1,0],[1,0,1]] \t";
    cout << solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} }) << endl;

    return 0;
}