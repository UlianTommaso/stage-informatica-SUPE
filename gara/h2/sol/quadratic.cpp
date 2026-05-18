#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class I>
int lis(vector<I> const& a) {
    int n = a.size();
    vector<int> d(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i])
                d[i] = max(d[i], d[j] + 1);
        }
    }

    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = max(ans, d[i]);
    }
    return ans;
}


int main() {
    int N; cin >> N;
    
    vector<pair<char, int>> v(N);

    for (int i = 0; i < N; i ++) {
        string s; cin >> s;
        v[i].first = s[0];
        int num = 0;
        for (int j = 1; j < s.size(); j ++){
            num *= 10;
            num += s[j]-'0';
        };
        v[i].second = num;
    }

    int res = 1e9;
    vector<char> permutations = {'P', 'S', 'U', 'W'};
    
    while(next_permutation(all(permutations))){


        vector<pair<pair<int, int>, int>> v_copy(N);

        map<char, int> ziopera;
        for (int j = 0; j < 4; j ++) {
            ziopera[permutations[j]] = j;
        }
        ziopera['E'] = 4;

        for (int i = 0; i < N; i++) v_copy[i] = {{ziopera[v[i].first], v[i].second}, i};
        sort(all(v_copy));
        vector<ll> new_pos(N);
        for (int i = 0; i < N; i ++) {
            auto [a, b] = v_copy[i];
            new_pos[i] = b;
        }
        int l = lis(new_pos);
        res = min(res, (int)N - l);
    }

    cout << res << '\n';

}
