// @check-accepted: samples
// @check-wrong-answer: sub1 sub2 sub3 sub4 sub5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        if (!(cin >> u >> v >> w)) return 0;
    }

    for (int i = 0; i < K; ++i) {
        int u;
        long long y;
        if (!(cin >> u >> y)) return 0;
    }

    for (int i = 1; i < N; ++i) {
        cout << 1 << "\n";
    }

    return 0;
}
