#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename t>
using ordered_set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename t> 
using ordered_set_desc = tree< t, null_type, greater<t>, rb_tree_tag, tree_order_statistics_node_update >;
const int mod = 1e9 + 7;
/* const int mod=998244353; */

// macros
#define ios std::ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);cout.precision(numeric_limits<double>::max_digits10);
#define sq(a) (a) * (a)
#define int long long
#define ll long long
#define ld long double 
#define vl __int128_t
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define all(container) container.begin(), container.end()
#define ff first
#define ss second
#define pb push_back
#define sz(x) ((int)(x).size())
#define endl '\n'
#define up(x,y) ((x+y-1)/y)
// loop
#define rep(v, s, e) for (int v = s; v < e; v++)
#define repe(v, s, e) for (int v = s; v <= e; v++)
#define repa(v, container) for (auto &v : container)
// vector
typedef vector<int> vi;
typedef pair<int, int> pii;
// heap
#define maxheap(t) priority_queue<t, vector<t>>
#define minheap(t) priority_queue<t, vector<t>, greater<t>>
// modular operations
int power_mod(int v, int n) {v %= mod;if(v == 0) return 0;n %= (mod - 1); int ret = 1;for(; n; n >>= 1, v = (v * v) % mod) if(n & 1) ret = (ret * v) % mod;return ret;}
int mod_sub(int x, int y) {x %= mod; y %= mod;return (x + mod - y) % mod;}
int mod_add(int x, int y) {x %= mod; y %= mod;return (x + y) % mod;}
int mod_mul(int x, int y) {x %= mod; y %= mod;return (x * y) % mod;}
int mod_inv(int x) {x %= mod;return power_mod(x, mod - 2);}
int mod_div(int x, int y) {x %= mod; y %= mod;return mod_mul(x, mod_inv(y));}
// modular operations

// bit operations
#define setcnt(x)   (popcount(static_cast<unsigned long long>(x)))
#define is_pow2(x)  ((x) > 0 && has_single_bit(static_cast<unsigned long long>(x)))
#define nxt_pow2(x) (bit_ceil(static_cast<unsigned long long>(x)))
#define prv_pow2(x) (bit_floor(static_cast<unsigned long long>(x)))
#define msb_idx(x)  ((x) == 0 ? -1 : (int)bit_width(static_cast<unsigned long long>(x)) - 1)
// numbers
ld logc(ld base, ld x) {return log2(x) /log2(base);} 
ll xor_upto(int n){return n%4==0?n:n%4==1?1:n%4==2?n+1:0;}
ll power(int base, int exp) { int res = 1; while (exp > 0) { if (exp&1) { res *= base; } base *= base; exp>>=1; } return res; }
template<class t> bool is_prime(t n){if(n<2)return 0;if(n%2==0)return n==2;for(t i=3;i<=n/i;i+=2)if(n%i==0)return 0;return 1;}


void solve(){
}



signed main(void){
    ios;
    // int t;
    // cin >> t;
    // while(t--)solve();
    solve();

    return 0;
}
