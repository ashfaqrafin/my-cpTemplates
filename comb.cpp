#include <vector>

// ============================== Combinatorics ==============================

const int MAX_COMBINATIONS = 2000005;

struct Combinations {
    std::vector<long long> factorial;
    std::vector<long long> inverseFactorial;
    int mod;

    explicit Combinations(int limit = MAX_COMBINATIONS, int mod = 1000000007)
        : factorial(limit + 1), inverseFactorial(limit + 1) {
        this->mod = mod;
        factorial[0] = 1;
        for (int i = 1; i <= limit; ++i) {
            factorial[i] = modMul(factorial[i - 1], i, mod);
        }

        inverseFactorial[limit] = modInv(factorial[limit], mod);
        for (int i = limit - 1; i >= 0; --i) {
            inverseFactorial[i] = modMul(inverseFactorial[i + 1], i + 1, mod);
        }
    }

    long long nCr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return modMul(factorial[n],
                      modMul(inverseFactorial[r], inverseFactorial[n - r], mod),
                      mod);
    }

    long long nPr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return modMul(factorial[n], inverseFactorial[n - r], mod);
    }
};
