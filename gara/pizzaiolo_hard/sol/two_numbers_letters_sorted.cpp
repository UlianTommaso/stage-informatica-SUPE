#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N; cin >> N;
    

    map<char, vector<int>> pos;
    for (int i = 0; i < N; i ++) {
        char c; int x; cin >> c >> x;
        pos[c].push_back(x);
    }  

    int res = 0;

    for (auto [c, v] : pos) {
        if (v.size() < 2) continue;
        if (v[0] > v[1]) res ++;
    }

    cout << res << '\n';
}
