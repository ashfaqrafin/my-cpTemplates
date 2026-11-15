
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
int nextPrime(int x) {
    if (x < 2) x = 2;

    while (x < N && spf[x] != x) {
        x++;
    }

    return x < N ? x : -1;
}
long long nextPrime(long long n) {
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    auto powerMod = [](u64 a, u64 e, u64 mod) {
        u64 result = 1;
        while (e) {
            if (e & 1)
                result = (u128)result * a % mod;
            a = (u128)a * a % mod;
            e >>= 1;
        }
        return result;
    };

    auto isPrime = [&](u64 x) {
        if (x < 2) return false;

        for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL,
                      13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
            if (x % p == 0) return x == p;
        }

        u64 d = x - 1, s = 0;
        while ((d & 1) == 0) d >>= 1, ++s;

        for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL,
                      450775ULL, 9780504ULL, 1795265022ULL}) {
            if (a % x == 0) continue;

            u64 y = powerMod(a % x, d, x);
            if (y == 1 || y == x - 1) continue;

            bool composite = true;
            for (u64 r = 1; r < s; ++r) {
                y = (u128)y * y % x;
                if (y == x - 1) {
                    composite = false;
                    break;
                }
            }

            if (composite) return false;
        }

        return true;
    };

    if (n <= 2) return 2;
    if (n % 2 == 0) ++n;

    while (!isPrime(n))
        n += 2;

    return n;
}
// Generate an array of only prime numbers up to n
vector<int> generatePrimes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }

    vector<int> primes;
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}
// Generate an array of only prime numbers up to n

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

// all divisors
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
// all divisors

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

double log_custom(double base, double x) {
    return log2(x) /log2(base);
}
