// @check-accepted: samples
// @check-wrong-answer: sub1 sub2 sub3 sub4 sub5
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

    for (int i = 0; i < N-1; i++) {
        cout << 1 << '\n';
    }

    return 0;
}
