// @check-accepted: samples sub2
// @check-time-limit-exceeded: sub3 sub4
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            k--; // to 0-based index
            t[k] = x;
        } else if (op == '?') {
            int x;
            cin >> x;
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (t[j] == x) {
                    count++;
                }
            }
            cout << count << "\n";
        }
    }
    return 0;
}
