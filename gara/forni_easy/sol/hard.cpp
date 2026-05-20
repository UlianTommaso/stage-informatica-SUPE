#include <bits/stdc++.h>

using namespace std;

const int nax = 6e5+5;

int ft[nax];

int n;

void update(int k, int v){
    k++;
    while(k < nax){
        ft[k] += v;
        k += k & (-k);
    }
}

int query(int k){
    k++;
    int res = 0;
    while(k > 0){
        res += ft[k];
        k -= k & (-k);
    }
    return res;
}

int range_query(int l, int r) {  // [l, r] entrambi inclusi
    if(l == 0) return query(r);
    return query(r) - query(l - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int q;
    cin >> n >> q;
    
    map<int,int> m;
    vector<int> e(n);
    vector<array<int,3>> qq(q);
    
    for(auto &x : e) {
        cin >> x;
        m[x] = 0;
    }

    for(int i = 0; i < q; i++){
        char c;
        int a, b;
        cin >> c >> a;
        if (c == '!') cin >> b;
        else b = a;
        qq[i][0] = c;
        qq[i][1] = a;
        qq[i][2] = b;
        if(c == '!') m[b] = 0;  // solo per '!' aggiungiamo b
    }

    // Compressione delle coordinate
    int p = 0;
    for(auto &x : m) {
        x.second = p++;
    }

    // Inizializzazione BIT
    for(int i = 0; i < n; i++) {
        update(m[e[i]], 1);
    }

    // Processamento delle query
    for(int j = 0; j < q; j++){
        auto [c, a, b] = qq[j];

        if(c == '!'){
            // Update: impiegato a (1-based) cambia stipendio a b
            int idx = a - 1;  // a è 1-based
            update(m[e[idx]], -1);
            e[idx] = b;
            update(m[e[idx]], 1);
        } else {
            // Query: stipendi nell'intervallo [a, b]
            auto it_low = m.lower_bound(a);
            auto it_up = m.upper_bound(b);
            
            if(it_low == m.end() || it_low->first > b) {
                cout << "0\n";
                continue;
            }
            
            int l = it_low->second;
            int r = (--it_up)->second;
            
            cout << range_query(l, r) << "\n";
        }
    }
    
    return 0;
}