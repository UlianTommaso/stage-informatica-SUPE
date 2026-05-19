// @check-accepted: samples sub1 sub2
// @check-zero: sub3 sub4 sub5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));
    for (int i = 1; i <= N; ++i) dist[i][i] = 0;

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    struct Chiosco {
        int u;
        long long y;
    };
    vector<Chiosco> chioschi(K);
    for (int i = 0; i < K; ++i) {
        cin >> chioschi[i].u >> chioschi[i].y;
    }

    // Floyd-Warshall
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 1; i < N; ++i) {
        bool can = false;
        for (int c = 0; c < K; ++c) {
            int h = chioschi[c].u;
            long long y = chioschi[c].y;
            if (dist[i][h] != INF && dist[h][N] != INF && dist[i][N] != INF) {
                if (dist[i][h] + dist[h][N] - y <= dist[i][N]) {
                    can = true;
                    break;
                }
            }
        }
        if (can) cout << 1 << "\n";
        else cout << 0 << "\n";
    }

    return 0;
}
