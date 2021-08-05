#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

vector<pair<int, int>> v;

int solution(vector<int> food_times, long long k) {
    long long size = food_times.size();
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        v.push_back(make_pair(food_times[i], i + 1));
        sum += food_times[i];
    }
    if (sum <= k)
        return -1;

    sort(v.begin(), v.end());
    long long foodtime = 0;
    long long eat = 0;
    auto it = v.begin();

    while (it != v.end()) {
        eat = size * (it->first - foodtime);
        if (eat <= k) {
            k -= eat;
            foodtime = it->first;
        }
        else {
            sort(it, v.end(), cmp);
            it += (k % size);
            return it->second;
        }
        size--;
        it++;
    }

    return -1;
}

int main()
{
    cout << solution({ 3,1,2 }, 5) << endl;

    return 0;
}