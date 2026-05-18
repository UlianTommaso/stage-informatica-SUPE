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
vector<int> lis(const vector<I>& S) {
    if (S.empty()) return {};
    vector<int> prev(S.size());
    typedef pair<I, int> p;
    vector<p> res;

    for (int i = 0; i < (int)S.size(); ++i) {
        auto it = lower_bound(res.begin(), res.end(), p{S[i], 0},
                              [](const p& a, const p& b){ return a.first < b.first; });
        if (it == res.end()) {
            res.emplace_back();
            it = res.end() - 1;
        }
        *it = {S[i], i};
        prev[i] = (it == res.begin() ? -1 : (it - 1)->second);
    }

    int L = (int)res.size();
    int cur = res.back().second;
    vector<int> ans(L);
    while (cur != -1) {
        ans[--L] = cur;
        cur = prev[cur];
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
        vi l = lis(new_pos);
        res = min(res, (int)N - (int)l.size());

    }

    cout << res << '\n';

}
