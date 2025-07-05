
#include <bits/stdc++.h>
using namespace std;
using int = long long;

// smallest prime factor
const int N = 1e7 + 1;
int spf[N];
void sieve() {
    for (int i = 1; i < N; i++)spf[i] = i;
    for (int i = 2; i * i < N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < N; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}
// smallest prime factor
