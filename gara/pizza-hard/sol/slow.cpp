// @check-accepted: samples sub1 sub2 sub3
// @check-time-limit-exceeded: sub4 sub5
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long weight;
};

vector<long long> dijkstra(int start, int N, const vector<vector<Edge>>& adj) {
    vector<long long> dist(N + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge : adj[u]) {
            if (dist[edge.to] > dist[u] + edge.weight) {
                dist[edge.to] = dist[u] + edge.weight;
                pq.push({dist[edge.to], edge.to});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, T;
    if (!(cin >> N >> M >> K >> T)) return 0;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    struct Chiosco {
        int u;
        long long y;
    };
    vector<Chiosco> chioschi(K);
    for (int i = 0; i < K; ++i) {
        cin >> chioschi[i].u >> chioschi[i].y;
    }

    vector<long long> distT = dijkstra(T, N, adj);
    vector<long long> distBeer(N + 1, INF);

    for (int c = 0; c < K; ++c) {
        int h = chioschi[c].u;
        long long y = chioschi[c].y;
        vector<long long> distH = dijkstra(h, N, adj);
        for (int i = 1; i <= N; ++i) {
            if (distH[i] != INF && distT[h] != INF) {
                distBeer[i] = min(distBeer[i], distH[i] + distT[h] - y);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (distBeer[i] <= distT[i]) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
