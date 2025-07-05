
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 1e9 + 9;
/* const int mod = 1e9 + 7; */
const int mod=998244353;
const long double fcomp = 1e-9;

// macros
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define endl '\n'
#define sq(a) (a) * (a)
#define MAX (int)1e18
#define int long long
#define double long double
#define all(container) container.begin(), container.end()
#define debug(x) cout << #x << " is " << x << endl
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
// loop
#define rep(v, s, e) for (int v = s; v < e; v++)
#define repe(v, s, e) for (int v = s; v <= e; v++)
#define repn(v, s, e) for (int v = s; v >= e; v--)
#define repc(v, s, e, custom) for (int v = s; v <= e; custom)
#define repa(v, container) for (auto &v : container)
// heap
#define maxHeap(t) priority_queue<t, vector<t>>
#define minHeap(t) priority_queue<t, vector<t>, greater<t>>
// vector
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
// pair
typedef pair<int, int> pii;
typedef pair<int, char> pic;
typedef pair<int, string> pis;

/*modular operations*/
int power_mod(int v, int n) {v %= mod;if(v == 0) return 0;n %= (mod - 1); int ret = 1;for(; n; n >>= 1, v = (v * v) % mod) if(n & 1) ret = (ret * v) % mod;return ret;}
int mod_sub(int x, int y) {x %= mod; y %= mod;return (x + mod - y) % mod;}
int mod_add(int x, int y) {x %= mod; y %= mod;return (x + y) % mod;}
int mod_mul(int x, int y) {x %= mod; y %= mod;return (x * y) % mod;}
int mod_inv(int x) {x %= mod;return power_mod(x, mod - 2);}
int mod_div(int x, int y) {x %= mod; y %= mod;return mod_mul(x, mod_inv(y));}
/*modular operations*/

/* combinatorics */
const int MAXC = 2000005;
vi fact, ifact;
void Combinatorics(){
    fact.resize(MAXC+1);
    ifact.resize(MAXC+1);

    fact[0] = 1;
    repe(i, 1, MAXC) {
        fact[i] = mod_mul(fact[i - 1], i);
    }
    ifact[MAXC] = mod_inv(fact[MAXC]);
    for (int i = MAXC - 1; i >= 0; --i) {
        ifact[i] = mod_mul(ifact[i+1], i+1);
    }
}
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r]));
}
int nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mod_mul(fact[n], ifact[n - r]);
}


int comb_big(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r;
    int num = 1, den = 1;
    for (int i = 1; i <= r; ++i) {
        int term = (int)((n - r + i) % mod);
        if (term < 0) term += mod;
        num = mod_mul(num, term);
        den = mod_mul(den, i);
    }
    return mod_mul(num, mod_inv(den));
}

int perm_big(int n, int r) {
    if (r < 0 || r > n) return 0;
    int res = 1;
    for (int i = 0; i < r; ++i) {
        int term = (int)((n - i) % mod);
        if (term < 0) term += mod;
        res = mod_mul(res, term);
    }
    return res;
}
/* combinatorics */


void solve(){
}

signed main(void){
    IOS;

    int t;
    cin >> t;
    while (t--)solve();

    return 0;
}
