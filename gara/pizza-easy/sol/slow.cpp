// @check-accepted: samples sub1 sub2 sub3
// @check-time-limit-exceeded: sub4 sub5
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<long long> t(N);
    for (int i = 1; i <= N - 1; ++i) {
        cin >> t[i];
    }

    struct Chiosco {
        int u;
        long long y;
    };
    vector<Chiosco> chioschi(K);
    for (int i = 0; i < K; ++i) {
        cin >> chioschi[i].u >> chioschi[i].y;
    }

    // P[i] is prefix sum of distances
    vector<long long> P(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        P[i] = P[i - 1] + t[i - 1];
    }

    for (int i = 1; i < N; ++i) {
        bool can = false;
        for (int j = 0; j < K; ++j) {
            int h = chioschi[j].u;
            long long y = chioschi[j].y;
            if (h >= i) {
                can = true;
                break;
            } else {
                long long dist = P[i] - P[h];
                if (2 * dist <= y) {
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
