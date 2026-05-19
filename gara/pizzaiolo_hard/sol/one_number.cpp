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

    bool is_c = false;
    for (int i = 0; i < N; i ++) {
        if (v[i][0] == 'E') {
            is_c = true;
        }   
    }

    if (v.back()[0] == 'E' || !is_c) {
        cout << 0 << '\n';
    }
    if (is_c && v.back()[0] != 'E') {
        cout << 1 << '\n';
    }
}
