#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Ottimizzazione I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; 
    if (!(cin >> N)) return 0;
    
    vector<char> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int res = 1e9;

    vector<char> permutations = {'C', 'D', 'S', 'W'};
    // Ordiniamo per ottenere la prima permutazione in ordine lessicografico
    sort(permutations.begin(), permutations.end());
    
    int ziopera[256];

    do {
        // Popoliamo la mappa veloce
        for (int j = 0; j < 4; j++) {
            ziopera[permutations[j]] = j;
        }

        // Convertiamo in anticipo i caratteri in numeri (0, 1, 2, 3) 
        // secondo la permutazione corrente per comodità
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            A[i] = ziopera[v[i]];
        }

        // ==========================================
        // INIZIO DP QUADRATICA O(N^2)
        // ==========================================
        
        // dp[i] memorizza la lunghezza massima della LNDS che termina esattamente all'indice i.
        // Ogni elemento da solo forma una sequenza valida lunga almeno 1.
        int lnds = (N > 0) ? 1 : 0;
        vector<int> dp(N, 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                // Se l'elemento in j è minore o uguale a quello in i (ordine non decrescente)
                if (A[j] <= A[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // Aggiorniamo il massimo globale
            lnds = max(lnds, dp[i]);
        }
        
        // ==========================================
        // FINE DP QUADRATICA
        // ==========================================

        res = min(res, N - lnds);

    } while (next_permutation(permutations.begin(), permutations.end()));

    cout << res << '\n';
    return 0;
}