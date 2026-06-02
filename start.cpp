#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename t>
using ordered_set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
/* const int mod=998244353; */

// macros
#define ios std::ios::sync_with_stdio(false); cin.tie(nullptr);cout.tie(nullptr);cout.precision(numeric_limits<double>::max_digits10);
#define sq(a) (a) * (a)
#define int long long
#define ll long long
#define ld long double
#define vl __int128
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define all(container) container.begin(), container.end()
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define endl '\n'
// loop
#define rep(v, s, e) for (int v = s; v < e; v++)
#define repe(v, s, e) for (int v = s; v <= e; v++)
#define repa(v, container) for (auto &v : container)
// vector
typedef vector<int> vi;
typedef vector<vector<int,int>> vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> s;
// pair
typedef pair<int, int> pii;
// heap
#define maxHeap(t) priority_queue<t, vector<t>>
#define minHeap(t) priority_queue<t, vector<t>, greater<t>>
// modular operations
int power_mod(int v, int n) {v %= mod;if(v == 0) return 0;n %= (mod - 1); int ret = 1;for(; n; n >>= 1, v = (v * v) % mod) if(n & 1) ret = (ret * v) % mod;return ret;}
int mod_sub(int x, int y) {x %= mod; y %= mod;return (x + mod - y) % mod;}
int mod_add(int x, int y) {x %= mod; y %= mod;return (x + y) % mod;}
int mod_mul(int x, int y) {x %= mod; y %= mod;return (x * y) % mod;}
int mod_inv(int x) {x %= mod;return power_mod(x, mod - 2);}
int mod_div(int x, int y) {x %= mod; y %= mod;return mod_mul(x, mod_inv(y));}
// modular operations

void solve(){

}


signed main(void){
    IOS;
    int t;
    cin >> t;
    while (t--)solve();

    return 0;
}
