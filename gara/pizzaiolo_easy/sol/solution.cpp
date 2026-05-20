#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    if (!(cin >> N)) return 0;
    
    vector<char> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int res = 1e9;

    vector<char> permutations = {'D', 'C', 'W', 'S'};
    // We sort it to get the lexicographically first permutation to start
    sort(permutations.begin(), permutations.end());
    
    do {
        map<char, int> ziopera;
        for (int j = 0; j < 4; j++) {
            ziopera[permutations[j]] = j;
        }
        ziopera['M'] = 4;

        vector<int> dp(5, 0);
        for (char c : v) {
            int x = ziopera[c];
            int max_prev = 0;
            for (int i = 0; i <= x; i++) {
                max_prev = max(max_prev, dp[i]);
            }
            dp[x] = max_prev + 1;
        }

        int lnds = 0;
        for (int i = 0; i < 5; i++) {
            lnds = max(lnds, dp[i]);
        }

        res = min(res, N - lnds);

    } while (next_permutation(permutations.begin(), permutations.end()));

    cout << res << '\n';
    return 0;
}
