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

long long binomialPower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result *= base;
        base *= base;
        exponent >>= 1;
    }
    return result;
}
