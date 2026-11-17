#include <string>
#include <vector>

// ============================ String Hashing ============================

struct StringHashing {
    static constexpr long long BASE = 31;

    std::string text;
    std::vector<long long> hashPrimes;
    std::vector<std::vector<long long>> forwardHash;
    std::vector<std::vector<long long>> reverseHash;
    std::vector<std::vector<long long>> powers;
    std::vector<std::vector<long long>> inversePowers;

    explicit StringHashing(std::string value,
                           std::vector<long long> primes =
                               {1000000007LL, 1000000009LL})
        : text(std::move(value)),
          hashPrimes(std::move(primes)),
          forwardHash(hashPrimes.size()),
          reverseHash(hashPrimes.size()),
          powers(hashPrimes.size()),
          inversePowers(hashPrimes.size()) {
        int n = static_cast<int>(text.size());

        for (int i = 0; i < static_cast<int>(hashPrimes.size()); ++i) {
            long long mod = hashPrimes[i];
            powers[i].assign(n + 1, 1);
            inversePowers[i].assign(n + 1, 0);

            for (int j = 1; j <= n; ++j) {
                powers[i][j] = powers[i][j - 1] * BASE % mod;
            }

            inversePowers[i][n] = modInv(powers[i][n], mod);
            for (int j = n - 1; j >= 0; --j) {
                inversePowers[i][j] =
                    inversePowers[i][j + 1] * BASE % mod;
            }

            forwardHash[i].assign(n, 0);
            reverseHash[i].assign(n, 0);

            for (int j = 0; j < n; ++j) {
                long long valueFromStart =
                    (text[j] - 'a' + 1LL) * powers[i][j] % mod;
                forwardHash[i][j] =
                    (valueFromStart +
                     (j > 0 ? forwardHash[i][j - 1] : 0LL)) %
                    mod;

                long long valueFromEnd =
                    (text[n - 1 - j] - 'a' + 1LL) * powers[i][j] % mod;
                reverseHash[i][j] =
                    (valueFromEnd +
                     (j > 0 ? reverseHash[i][j - 1] : 0LL)) %
                    mod;
            }
        }
    }

    std::vector<long long> substringHash(int left, int right) const {
        std::vector<long long> result(hashPrimes.size());
        for (int i = 0; i < static_cast<int>(hashPrimes.size()); ++i) {
            long long mod = hashPrimes[i];
            long long before = left > 0 ? forwardHash[i][left - 1] : 0;
            long long difference = modSub(forwardHash[i][right], before, mod);
            result[i] =
                modMul(difference, inversePowers[i][left], mod);
        }
        return result;
    }

    std::vector<long long> reverseSubstringHash(int left, int right) const {
        int n = static_cast<int>(text.size());
        int reversedLeft = n - 1 - right;
        int reversedRight = n - 1 - left;
        std::vector<long long> result(hashPrimes.size());

        for (int i = 0; i < static_cast<int>(hashPrimes.size()); ++i) {
            long long mod = hashPrimes[i];
            long long before =
                reversedLeft > 0 ? reverseHash[i][reversedLeft - 1] : 0;
            long long difference =
                modSub(reverseHash[i][reversedRight], before, mod);
            result[i] =
                modMul(difference, inversePowers[i][reversedLeft], mod);
        }
        return result;
    }

    bool isPalindrome(int left, int right) const {
        return substringHash(left, right) == reverseSubstringHash(left, right);
    }
};
