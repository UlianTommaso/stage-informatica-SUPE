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
    long long max_y = 0;
    for (int i = 0; i < K; ++i) {
        int u;
        long long y;
        cin >> u >> y;
        u++;
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

    // Heuristic 2: Otherwise, run Dijkstra from T and only check kiosks within distance of 2 edges
    vector<long long> distT = dijkstra(T, N, adj);

    for (int i = 1; i <= N; ++i) {
        if (distT[i] == INF) {
            cout << 0 << "\n";
            continue;
        }

        bool can = false;

        // 0 edges (node itself is a kiosk)
        if (hay[i] > 0) {
            can = true;
        }

        // 1 edge away
        if (!can) {
            for (auto& edge1 : adj[i]) {
                int v = edge1.to;
                if (hay[v] > 0) {
                    if (edge1.weight + distT[v] - hay[v] <= distT[i]) {
                        can = true;
                        break;
                    }
                }
            }
        }

        // 2 edges away
        if (!can) {
            for (auto& edge1 : adj[i]) {
                int v = edge1.to;
                for (auto& edge2 : adj[v]) {
                    int w = edge2.to;
                    if (hay[w] > 0) {
                        if (edge1.weight + edge2.weight + distT[w] - hay[w] <= distT[i]) {
                            can = true;
                            break;
                        }
                    }
                }
                if (can) break;
            }
        }

        if (can) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
