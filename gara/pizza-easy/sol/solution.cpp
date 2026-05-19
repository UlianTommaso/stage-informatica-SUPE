// @check-accepted: samples sub1 sub2 sub3 sub4 sub5
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const long long INF = 1e18;

char buf[1 << 20];
int pos = 0, len = 0;
inline char getChar() {
    if (pos == len) {
        pos = 0;
        len = fread(buf, 1, sizeof(buf), stdin);
        if (len == 0) return EOF;
    }
    return buf[pos++];
}
inline long long readLong() {
    long long x = 0;
    char c = getChar();
    while (c < '0' || c > '9') {
        if (c == EOF) return -1;
        c = getChar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getChar();
    }
    return x;
}

char out_buf[1 << 20];
int out_pos = 0;
inline void writeChar(char c) {
    if (out_pos == sizeof(out_buf)) {
        fwrite(out_buf, 1, out_pos, stdout);
        out_pos = 0;
    }
    out_buf[out_pos++] = c;
}

int main() {
    long long N = readLong();
    long long K = readLong();
    if (N == -1) return 0;

    vector<long long> t(N); // t[i] is distance between i and i+1
    for (int i = 1; i <= N - 1; ++i) {
        t[i] = readLong();
    }

    vector<long long> max_y(N + 1, -1);
    for (int i = 0; i < K; ++i) {
        int u = readLong();
        long long y = readLong();
        max_y[u] = max(max_y[u], y);
    }

    // P[i] is the distance from 1 to i
    vector<long long> P(N + 1, 0);
    for (int i = 2; i <= N; ++i) {
        P[i] = P[i - 1] + t[i - 1];
    }

    // val[i] = P[i] + y_i / 2 if chiosco at i
    // pref_max[i] = max_{j < i} val[j]
    vector<long long> pref_max(N + 1, -INF);
    long long current_max = -INF;
    for (int i = 1; i <= N; ++i) {
        pref_max[i] = current_max;
        if (max_y[i] != -1) {
            current_max = max(current_max, P[i] + max_y[i] / 2);
        }
    }

    // suff_has[i] is true if there is a chiosco at some h >= i
    vector<bool> suff_has(N + 1, false);
    bool has_chiosco = false;
    for (int i = N; i >= 1; --i) {
        if (max_y[i] != -1) {
            has_chiosco = true;
        }
        suff_has[i] = has_chiosco;
    }

    // Output for 1..N-1
    for (int i = 1; i < N; ++i) {
        if (suff_has[i] || P[i] <= pref_max[i]) {
            writeChar('1');
        } else {
            writeChar('0');
        }
        writeChar('\n');
    }

    if (out_pos > 0) {
        fwrite(out_buf, 1, out_pos, stdout);
    }

    return 0;
}
