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

    int l = lis(v);
    cout << N - l << '\n';
}
