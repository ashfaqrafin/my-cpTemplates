#include <cstdint>

// ============================ Modular Arithmetic ============================

int powerMod(long long base, long long exponent, long long mod) {
    base %= mod;
    if (base == 0) return 0;
    exponent %= mod - 1;

    long long result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = result * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return static_cast<int>(result);
}

int modAdd(long long x, long long y, long long mod) {
    x %= mod;
    y %= mod;
    return static_cast<int>((x + y) % mod);
}

int modSub(long long x, long long y, long long mod) {
    x %= mod;
    y %= mod;
    return static_cast<int>((x - y + mod) % mod);
}

int modMul(long long x, long long y, long long mod) {
    x %= mod;
    y %= mod;
    return static_cast<int>(x * y % mod);
}

int modInv(long long x, long long mod) {
    x %= mod;
    return powerMod(x, mod - 2, mod);
}

int modDiv(long long x, long long y, long long mod) {
    x %= mod;
    y %= mod;
    return modMul(x, modInv(y, mod), mod);
}
