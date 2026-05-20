#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main() {

    int N; 
    if (!(cin >> N)) return 0;
    
    vector<char> v(N);
    set<int> tastes;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        // Se il gusto non è ancora nel nostro vettore, lo aggiungiamo
        tastes.insert(v[i]);
    }

    if (tastes.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    int res = 1e9;

    vector<char> tungtung;
    for (auto x : tastes) tungtung.push_back(x);

    // Ordiniamo per assicurarci di partire dalla primissima permutazione (es. C -> W)
    sort(tungtung.begin(), tungtung.end());


    for (int k = 0; k < 2; k ++) {
        // Regola di Tommaso: la 'M' deve stare alla fine. 
        // Se in questa permutazione la 'M' capita al primo posto, saltiamo il calcolo.
        if (tungtung[0] == 'M') {
            next_permutation(tungtung.begin(), tungtung.end());
            continue;
        }

        map<char, int> sahur;
        for (int j = 0; j < 2; j++) {
            sahur[tungtung[j]] = j;
        }

        // Inizializziamo entrambe a 0 (ho corretto dp_1 = 0, che è lo standard per il LNDS)
        int dp_0 = 0;
        int dp_1 = 0; 

        for (char c : v) {
            int x = sahur[c];
            
            if (x == 0) {
                // Può estendere solo una sottosequenza fatta di soli 0
                dp_0 = dp_0 + 1;
            } else if (x == 1) {
                // Può estendere la migliore sottosequenza trovata finora (che finisca con 0 o con 1)
                dp_1 = max(dp_0, dp_1) + 1;
            }
        }

        // Il risultato finale è il massimo tra le due
        int lnds = max(dp_0, dp_1);

        res = min(res, N - lnds);

        next_permutation(tungtung.begin(), tungtung.end());
    }

    cout << res << '\n';
    return 0;
}