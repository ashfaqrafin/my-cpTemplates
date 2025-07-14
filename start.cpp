
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int INF = 2e18;
const int mod = 1e9 + 7;
/* const int mod=998244353; */

// macros
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define sq(a) (a) * (a)
#define int long long
#define double long double
#define MAX (int)1e18
#define all(container) container.begin(), container.end()
#define debug(x) cout << #x << " is " << x << endl
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define mk make_pair
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define gap " "
#define minus cout<<-1<<endl
#define endl '\n'
// loop
#define rep(v, s, e) for (int v = s; v < e; v++)
#define repe(v, s, e) for (int v = s; v <= e; v++)
#define repn(v, s, e) for (int v = s; v >= e; v--)
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


void solve(){
}

signed main(void){
    IOS;

    int t;
    cin >> t;
    while (t--)solve();

    return 0;
}
