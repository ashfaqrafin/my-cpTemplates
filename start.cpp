
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
/* combinatorics */



void preComputations(){
}


void solve(){

}

signed main(void){
    IOS;

    int t;
    cin >> t;
    preComputations();
    while (t--)solve();

    return 0;
}
