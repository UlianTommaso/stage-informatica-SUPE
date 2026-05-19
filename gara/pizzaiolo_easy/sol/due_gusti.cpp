#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int N; 
    if (!(cin >> N)) return 0;
    
    vector<char> v(N);
    vector<char> tastes; // Per salvare i due gusti presenti nel testcase
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        // Se il gusto non è ancora nel nostro vettore, lo aggiungiamo
        if (find(tastes.begin(), tastes.end(), v[i]) == tastes.end()) {
            tastes.push_back(v[i]);
        }
    }

    int res = 1e9;

    // Ordiniamo per assicurarci di partire dalla primissima permutazione (es. C -> W)
    sort(tastes.begin(), tastes.end());
    
    do {
        // Regola di Tommaso: la 'M' deve stare alla fine. 
        // Se in questa permutazione la 'M' capita al primo posto, saltiamo il calcolo.
        if (tastes.size() > 1 && tastes[0] == 'M') {
            continue;
        }

        map<char, int> ziopera;
        for (int j = 0; j < tastes.size(); j++) {
            ziopera[tastes[j]] = j;
        }

        // DP identica alla tua, ma grande quanto il numero di gusti (2)
        vector<int> dp(tastes.size(), 0);
        for (char c : v) {
            int x = ziopera[c];
            int max_prev = 0;
            for (int i = 0; i <= x; i++) {
                max_prev = max(max_prev, dp[i]);
            }
            dp[x] = max_prev + 1;
        }

        int lnds = 0;
        for (int i = 0; i < tastes.size(); i++) {
            lnds = max(lnds, dp[i]);
        }

        res = min(res, N - lnds);

    } while (next_permutation(tastes.begin(), tastes.end()));

    cout << res << '\n';
    return 0;
}