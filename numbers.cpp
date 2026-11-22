#include <bits/stdc++.h>
using namespace std;

// ============================== Number Theory ==============================

// Linear sieve / smallest prime factor.
vector<int> buildSieve(int limit) {
    vector<int> smallestPrime(limit + 1);
    iota(smallestPrime.begin(), smallestPrime.end(), 0);

    for (int i = 2; 1LL * i * i <= limit; ++i) {
        if (smallestPrime[i] != i) continue;
        for (int j = i * i; j <= limit; j += i) {
            if (smallestPrime[j] == j) smallestPrime[j] = i;
        }
    }
    return smallestPrime;
}

// Generate all primes up to limit.
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    if (limit >= 0) isPrime[0] = false;
    if (limit >= 1) isPrime[1] = false;

    for (int p = 2; 1LL * p * p <= limit; ++p) {
        if (!isPrime[p]) continue;
        for (int multiple = p * p; multiple <= limit; multiple += p) {
            isPrime[multiple] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }
    return primes;
}

// Generate all positive divisors.
vector<long long> getDivisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        divisors.push_back(i);
        if (i * i != n) divisors.push_back(n / i);
    }
    return divisors;
}

long long countDivisors(long long n) {
    long long result = 1;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;

        int exponent = 0;
        while (n % p == 0) {
            n /= p;
            ++exponent;
        }
        result *= exponent + 1;
    }
    if (n > 1) result *= 2;
    return result;
}

// Returns {prime, exponent} pairs.
// For 32-bit values.
vector<pair<long long, int>> getPrimeFactorsSmall(long long n) {
    vector<pair<long long, int>> result;
    if (n <= 1) return result;

    for (long long p = 2; p * p <= n; p += (p == 2 ? 1 : 2)) {
        if (n % p != 0) continue;

        int exponent = 0;
        while (n % p == 0) {
            n /= p;
            ++exponent;
        }
        result.push_back({p, exponent});
    }

    if (n > 1) result.push_back({n, 1});
    return result;
}

// Returns {prime, exponent} pairs.
// For large 64-bit values.
vector<pair<long long, int>> getPrimeFactorsLarge(long long n) {
    vector<pair<long long, int>> result;
    if (n <= 1) return result;

    using ull = unsigned long long;
    using u128 = __uint128_t;

    auto multiplyMod = [](ull a, ull b, ull mod) {
        return (ull)((u128)a * b % mod);
    };

    auto powerMod = [&](ull base, ull exponent, ull mod) {
        ull result = 1;
        while (exponent) {
            if (exponent & 1) result = multiplyMod(result, base, mod);
            base = multiplyMod(base, base, mod);
            exponent >>= 1;
        }
        return result;
    };

    auto isPrime = [&](ull n) -> bool {
        if (n < 2) return false;

        static constexpr ull smallPrimes[] = {
            2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37
        };
        for (ull p : smallPrimes) {
            if (n % p == 0) return n == p;
        }

        ull d = n - 1;
        int s = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            ++s;
        }

        static constexpr ull bases[] = {
            2, 325, 9375, 28178, 450775, 9780504, 1795265022
        };
        for (ull a : bases) {
            if (a % n == 0) continue;

            ull x = powerMod(a % n, d, n);
            if (x == 1 || x == n - 1) continue;

            bool composite = true;
            for (int r = 1; r < s; ++r) {
                x = multiplyMod(x, x, n);
                if (x == n - 1) {
                    composite = false;
                    break;
                }
            }
            if (composite) return false;
        }
        return true;
    };

    mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );

    auto pollardRho = [&](ull n) -> ull {
        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;

        while (true) {
            ull c = rng() % (n - 1) + 1;
            ull x = rng() % (n - 2) + 2;
            ull y = x;
            ull d = 1;

            for (ull length = 1; d == 1; length <<= 1) {
                x = y;
                for (ull i = 0; i < length; ++i) {
                    u128 next = (u128)multiplyMod(y, y, n) + c;
                    if (next >= n) next -= n;
                    y = (ull)next;

                    d = gcd(x > y ? x - y : y - x, n);
                    if (d != 1) break;
                }
            }
            if (d != n) return d;
        }
    };

    unordered_map<ull, int> exponent;
    auto factor = [&](auto&& self, ull n) -> void {
        if (n == 1) return;
        if (isPrime(n)) {
            ++exponent[n];
            return;
        }

        ull divisor = pollardRho(n);
        self(self, divisor);
        self(self, n / divisor);
    };
    factor(factor, (ull)n);

    result.reserve(exponent.size());
    for (const auto& [prime, count] : exponent) {
        result.push_back({(long long)prime, count});
    }
    return result;
}

long long binomialPower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result *= base;
        base *= base;
        exponent >>= 1;
    }
    return result;
}
