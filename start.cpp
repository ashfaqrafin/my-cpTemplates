#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using int64 = long long;
using int128 = __int128_t;

template <typename T>
using orderedSet =
    tree<T, null_type, less<T>, rb_tree_tag,
         tree_order_statistics_node_update>;

template <typename T>
using orderedMultiset =
    tree<T, null_type, less_equal<T>, rb_tree_tag,
         tree_order_statistics_node_update>;

constexpr int64 MOD = 1'000'000'007;
// constexpr int64 MOD = 998244353;

// ============================== Macros ==============================

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (static_cast<int>((x).size()))
#define ff first
#define ss second

using vi = vector<int64>;
using vvi = vector<vi>;
using pii = pair<int64, int64>;

// ========================= Modular Arithmetic ======================

int64 powerMod(int64 base, int64 exponent, int64 mod = MOD) {
    base %= mod;
    int64 result = 1;
    while (exponent > 0) {
        if (exponent & 1) result = result * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    return result;
}

int64 modAdd(int64 x, int64 y) {
    x %= MOD;
    y %= MOD;
    return (x + y) % MOD;
}

int64 modSub(int64 x, int64 y) {
    x %= MOD;
    y %= MOD;
    return (x - y + MOD) % MOD;
}

int64 modMul(int64 x, int64 y) {
    x %= MOD;
    y %= MOD;
    return x * y % MOD;
}

int64 modInv(int64 x) {
    return powerMod(x, MOD - 2);
}

// =============================== Solver ============================

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases = 1;
    cin >> testCases;
    while (testCases--) solve();
    return 0;
}
