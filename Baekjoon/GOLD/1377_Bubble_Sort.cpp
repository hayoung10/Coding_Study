#include <iostream>
#include <algorithm> // pair, sort, max
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, A[i].second - i);
    cout << ans + 1 << endl;

    return 0;
}