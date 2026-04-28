
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


int power(int base, int exp) {
    int res = 1;
    while (exp > 0) {
        if (exp&1) { 
            res *= base;
        }
        base *= base; 
        exp>>=1;
    }
    return res;
}

// divisors
vector<int> getDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

ll countDivisors(ll x) {
    ll count = 1;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ll exponent = 0;
            while (x % i == 0) {
                x /= i;
                exponent++;
            }
            count *= (exponent + 1);
        }
    }
    if (x > 1) { 
        count <<=1;
    }
    return count;
}

