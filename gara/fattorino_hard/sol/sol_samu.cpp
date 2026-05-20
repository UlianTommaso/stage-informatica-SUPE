#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MAXN = 1e5;

vector<pair<int, ll>> adj[MAXN];

int main() {
    int N, M, K, T; cin >> N >> M >> K >> T;

    for (int i = 0; i < M; i ++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<pair<int, ll>> hays(K);
    for (int i = 0; i < K; i ++) {
        int c, y; cin >> c >> y;
        hays[i] = {c, y};
    }

    vector<ll> dist_toppo(N, 1e18);
    priority_queue<pair<ll, int>> pq;
    vector<int> v(N);
    dist_toppo[T] = 0;
    pq.push({0,T});
    while (!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();
        if (v[u]) continue;
        v[u] = 1;

        for (auto [x, w] : adj[u]) {
            if (dist_toppo[x] > dist_toppo[u] + w) {
                dist_toppo[x] = dist_toppo[u] + w;
                pq.push({-dist_toppo[x], x});
            }
        }
    }

    vector<ll> dist_hays(N, 1e18);
    // pq vuota
    fill(v.begin(), v.end(), 0);
    for (auto [c, y] : hays) {
        dist_hays[c] = dist_toppo[c] - y;
        pq.push({-dist_hays[c], c});
    }
    while (!pq.empty()) {
        auto [_, u] = pq.top(); pq.pop();
        if (v[u]) continue;
        v[u] = 1;

        for (auto [x, w] : adj[u]) {
            if (dist_hays[x] > dist_hays[u] + w) {
                dist_hays[x] = dist_hays[u] + w;
                pq.push({-dist_hays[x], x});
            }
        }
    }

    for (int i = 0; i < N; i ++) {
        cout << (dist_hays[i] <= dist_toppo[i]) << '\n';
    }

}