#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<vector<int>> group;
vector<pair<int, pair<int, int>>> cost;
vector<int> parent;

void bfs(int x, int y, int gnum, vector<vector<int>> land, int height) { // 그룹 만들기
    group[x][y] = gnum;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < land.size() && 0 <= ny && ny < land.size()) {
            if (group[nx][ny] == 0 && abs(land[x][y] - land[nx][ny]) <= height) {
                bfs(nx, ny, gnum, land, height);
            }
        }
    }
}

int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}

bool same_parent(int a, int b) { // 같은 부모인지 확인
    a = find_parent(a);
    b = find_parent(b);
    if (a == b) return true;
    return false;
}

void union_ab(int a, int b) { // 서로 다른 부모일 경우 두 노드를 연결
    a = find_parent(a);
    b = find_parent(b);
    parent[b] = a;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int lsize = land.size();
    group = vector<vector<int>>(lsize, vector<int>(lsize, 0));

    int x = 0, y = 0, gnum = 1;
    for (int i = 0; i < lsize; i++) {
        for (int j = 0; j < lsize; j++) {
            if (group[i][j] == 0) {
                bfs(i, j, gnum, land, height);
                gnum++;
            }
        }
    }
    for (int i = 0; i < lsize; i++) {
        for (int j = 0; j < lsize; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (0 <= nx && nx < lsize && 0 <= ny && ny < lsize) {
                    if (group[i][j] != group[nx][ny])
                        cost.push_back(make_pair(abs(land[i][j] - land[nx][ny]), make_pair(group[i][j], group[nx][ny])));
                }
            }
        }
    }

    // Kruskal
    parent = vector<int>(gnum);
    sort(cost.begin(), cost.end());
    for (int i = 1; i < gnum; i++)
        parent[i] = i;
    for (int i = 0; i < cost.size(); i++) {
        int a = cost[i].second.first;
        int b = cost[i].second.second;
        if (!same_parent(a, b)) {
            union_ab(a, b);
            answer += cost[i].first;
        }
    }

    return answer;
}

int main()
{
    cout << "land \t\t\t\t\t\t\theight \tresult" << endl;

    cout << "[[1,4,8,10],[5,5,5,5],[10,10,10,10],[10,10,10,20]] \t3 \t";
    cout << solution({ {1,4,8,10},{5,5,5,5},{10,10,10,10},{10,10,10,20} }, 3) << endl;

    return 0;
}