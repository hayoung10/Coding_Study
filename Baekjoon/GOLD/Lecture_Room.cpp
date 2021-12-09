#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int stime, etime;
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> room;

void greedy_algorithm() {
	room.push_back(pq.top().second);
	pq.pop();
	
	while (!pq.empty()) {
		int l_start = pq.top().first;
		int l_end = pq.top().second;
		pq.pop();

		bool check = false;
		for (int i = 0; i < room.size(); i++) {
			if (room[i] <= l_start) {
				room[i] = l_end;
				check = true;
				break;
			}
		}
		if (!check)
			room.push_back(l_end);
	}
}

int main()
{
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num >> stime >> etime;
		pq.push({stime, etime});
	}

	greedy_algorithm();
	cout << room.size() << endl;

	return 0;
}