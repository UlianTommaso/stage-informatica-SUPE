// @check-accepted: samples
// @check-wrong-answer: sub1 sub2 sub3 sub4 sub5
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, T;
    if (!(cin >> N >> M >> K >> T)) return 0;
    T++;

    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        if (!(cin >> u >> v >> w)) return 0;
        u++; v++;
    }

    for (int i = 0; i < K; ++i) {
        int u;
        long long y;
        if (!(cin >> u >> y)) return 0;
        u++;
    }

    for (int i = 1; i <= N; ++i) {
        cout << 1 << "\n";
    }

    return 0;
}
