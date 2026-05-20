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

struct State {
    long long dist;
    int u;
    int kiosk;

    bool operator>(const State& other) const {
        return dist > other.dist;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, T;
    if (!(cin >> N >> M >> K >> T)) return 0;
    T++;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u++; v++;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> hay(N + 1, 0);
    vector<int> kiosks;
    long long max_y = 0;
    for (int i = 0; i < K; ++i) {
        int u;
        long long y;
        cin >> u >> y;
        u++;
        if (hay[u] == 0) {
            kiosks.push_back(u);
        }
        hay[u] = max(hay[u], y);
        max_y = max(max_y, y);
    }

    // Heuristic 1: If there is a mega-kiosk, the answer is almost certainly 1 for everyone
    if (max_y >= 500000000LL) {
        for (int i = 1; i <= N; ++i) {
            cout << 1 << "\n";
        }
        return 0;
    }

    // Dijkstra from T
    vector<long long> distT(N + 1, INF);
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        distT[T] = 0;
        pq.push({0, T});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > distT[u]) continue;
            for (auto& edge : adj[u]) {
                if (distT[edge.to] > distT[u] + edge.weight) {
                    distT[edge.to] = distT[u] + edge.weight;
                    pq.push({distT[edge.to], edge.to});
                }
            }
        }
    }

    // Bounded multisource Dijkstra from all kiosks (keep top 3 closest kiosks)
    vector<vector<pair<long long, int>>> best_kiosks(N + 1);
    priority_queue<State, vector<State>, greater<State>> pq;

    for (int k : kiosks) {
        pq.push({0, k, k});
    }

    while (!pq.empty()) {
        auto [d, u, kiosk] = pq.top();
        pq.pop();

        // Check if we already have this kiosk for u, or if we already have 3 kiosks
        bool has_kiosk = false;
        for (auto& p : best_kiosks[u]) {
            if (p.second == kiosk) {
                has_kiosk = true;
                break;
            }
        }
        if (has_kiosk) continue;
        if (best_kiosks[u].size() >= 3) continue;

        best_kiosks[u].push_back({d, kiosk});

        for (auto& edge : adj[u]) {
            if (best_kiosks[edge.to].size() < 3) {
                pq.push({d + edge.weight, edge.to, kiosk});
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (distT[i] == INF) {
            cout << 0 << "\n";
            continue;
        }

        bool can = false;
        for (auto& p : best_kiosks[i]) {
            long long d_to_k = p.first;
            int k = p.second;
            if (d_to_k + distT[k] - hay[k] <= distT[i]) {
                can = true;
                break;
            }
        }

        if (can) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
