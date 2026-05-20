#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N; cin >> N;
    
    vector<string> v(N);

    for (int i = 0; i < N; i ++) {
        cin >> v[i];
    }

    bool is_m = false;
    for (int i = 0; i < N; i ++) {
        if (v[i][0] == 'M') {
            is_m = true;
        }   
    }

    if (v.back()[0] == 'M' || !is_m) {
        cout << 0 << '\n';
    }
    if (is_m && v.back()[0] != 'M') {
        cout << 1 << '\n';
    }
}
