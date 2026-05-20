// @check-accepted: samples sub2 sub3 sub4
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> t(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
        freq[t[i]]++;
    }

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            k--; // to 0-based index
            
            // Decrement frequency of the old temperature
            freq[t[k]]--;
            if (freq[t[k]] == 0) {
                freq.erase(t[k]);
            }
            
            // Update temperature and increment frequency of new temperature
            t[k] = x;
            freq[t[k]]++;
        } else if (op == '?') {
            int x;
            cin >> x;
            auto it = freq.find(x);
            if (it != freq.end()) {
                cout << it->second << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
