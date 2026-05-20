// @check-accepted: samples sub3
// @check-wrong-answer: sub2 sub4
#include <iostream>
#include <vector>

using namespace std;

// Maximum temperature value for Subtask 3 is 10^6
const int MAX_VAL = 1000005;
int freq[MAX_VAL];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        if (t[i] < MAX_VAL) {
            freq[t[i]]++;
        }
    }

    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        if (op == '!') {
            int k, x;
            cin >> k >> x;
            k--; // to 0-based index
            
            if (t[k] < MAX_VAL) {
                freq[t[k]]--;
            }
            t[k] = x;
            if (t[k] < MAX_VAL) {
                freq[t[k]]++;
            }
        } else if (op == '?') {
            int x;
            cin >> x;
            if (x < MAX_VAL) {
                cout << freq[x] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}
