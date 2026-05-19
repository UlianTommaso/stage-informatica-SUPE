// @check-accepted: samples sub1 sub2 sub3 sub4 sub5
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

const long long INF = 1e18;

struct Pasture {
	long long cost;
	int index;
	bool had_hay;

	bool operator<(const Pasture &other) const {
		return cost > other.cost;  // For priority queue
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k, T;
	if (!(cin >> n >> k >> T)) return 0;
    T--;
	vector<vector<pair<int, long long>>> adj(n);
	for (int i = 0; i < n-1; i++) {
        long long w;
		cin  >> w;
		adj[i].push_back({i+1, w});
		adj[i+1].push_back({i, w});
	}

	vector<long long> hay(n, 0);
	for (int i = 0; i < k; i++) {
		int index;
        long long yumminess;
		cin >> index >> yumminess;
		index--;
		hay[index] = max(hay[index], yumminess);
	}

	priority_queue<Pasture> pq;

	vector<array<long long, 2>> dist(n, {INF, INF});

	dist[T][0] = 0;  // Distance to barn without hay
	pq.push({0, T, false});

	if (hay[T] > 0) {
		dist[T][1] = 0;
		pq.push({-hay[T], T, true});
	}

	while (!pq.empty()) {
		auto pasture = pq.top();
		pq.pop();

		long long cost = pasture.cost;
		int index = pasture.index;
		bool had_hay = pasture.had_hay;

		if (dist[index][had_hay] < cost) continue;

		for (auto &[next, w] : adj[index]) {
			long long new_cost = cost + w;

			if (had_hay) {
				if (dist[next][1] > new_cost) {
					dist[next][1] = new_cost;
					pq.push({new_cost, next, true});
				}
			} else {
				if (dist[next][0] > new_cost) {
					dist[next][0] = new_cost;
					pq.push({new_cost, next, false});
				}

				if (hay[next] > 0 && dist[next][1] > new_cost - hay[next]) {
					dist[next][1] = new_cost - hay[next];
					pq.push({new_cost - hay[next], next, true});
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (dist[i][1] <= dist[i][0]) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
    return 0;
}
