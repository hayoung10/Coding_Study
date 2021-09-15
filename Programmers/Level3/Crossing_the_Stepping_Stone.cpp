#include <iostream>
#include <algorithm> // max_element
#include <vector>
using namespace std;

bool BinarySearch(vector<int>& stones, int k, int mid) {
    int count = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid <= 0) count++;
        else count = 0;
        if (count >= k) return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int left = 1, right = *max_element(stones.begin(), stones.end());
    int count = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (BinarySearch(stones, k, mid)) right = mid - 1;
        else left = mid + 1;
    }

    return left;
}

int main()
{
    cout << "stones \t\t\tk \tresult" << endl;
    cout << "[2,4,5,3,2,1,4,2,5,1] \t3 \t" << solution({ 2,4,5,3,2,1,4,2,5,1 }, 3) << endl;

    return 0;
}