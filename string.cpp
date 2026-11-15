struct Hashing{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    // 1000000021 1000000033
    const ll base = 31;
    vector<vector<ll>> hashValues;
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;
    Hashing(string a){
        primes = sz(hashPrimes);
        hashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);
        s = a;
        n = s.length(); 
        for(int i = 0; i < sz(hashPrimes); i++) {
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);
            powersOfBase[i][0] = 1;
            for(int j = 1; j <= n; j++){
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % hashPrimes[i];
            }
            inversePowersOfBase[i][n] = mod_inv(powersOfBase[i][n], hashPrimes[i]);
            for(int j = n - 1; j >= 0; j--){
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, hashPrimes[i]);
            } 
        }
        for(int i = 0; i < sz(hashPrimes); i++) {
            hashValues[i].resize(n);
            for(int j = 0; j < n; j++){
                hashValues[i][j] = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % hashPrimes[i];
                hashValues[i][j] = (hashValues[i][j] + (j > 0 ? hashValues[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r){
        vector<ll> hash(primes);
        for(int i = 0; i < primes; i++){
            ll val1 = hashValues[i][r];
            ll val2 = l > 0 ? hashValues[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePowersOfBase[i][l], hashPrimes[i]);
        }
        return hash;
    }
};

struct Hashing {
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    // forward hashes
    vector<vector<ll>> hashValues;
    // reverse hashes
    vector<vector<ll>> reverseHashValues;
    // powers and inverses
    vector<vector<ll>> powersOfBase;
    vector<vector<ll>> inversePowersOfBase;

    Hashing(string a) {
        s = a;
        n = s.length();
        primes = hashPrimes.size();

        hashValues.resize(primes);
        reverseHashValues.resize(primes);
        powersOfBase.resize(primes);
        inversePowersOfBase.resize(primes);

        // precompute powers and inverses
        for (int i = 0; i < primes; i++) {
            ll mod = hashPrimes[i];
            powersOfBase[i].resize(n + 1);
            inversePowersOfBase[i].resize(n + 1);

            powersOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                powersOfBase[i][j] = (base * powersOfBase[i][j - 1]) % mod;
            }

            // inverse of base^n
            inversePowersOfBase[i][n] = mod_inv(powersOfBase[i][n], mod);
            for (int j = n - 1; j >= 0; j--) {
                inversePowersOfBase[i][j] = mod_mul(inversePowersOfBase[i][j + 1], base, mod);
            }
        }

        // compute forward hash values
        for (int i = 0; i < primes; i++) {
            ll mod = hashPrimes[i];
            hashValues[i].resize(n);
            for (int j = 0; j < n; j++) {
                ll v = ((s[j] - 'a' + 1LL) * powersOfBase[i][j]) % mod;
                hashValues[i][j] = (v + (j > 0 ? hashValues[i][j - 1] : 0LL)) % mod;
            }
        }

        // compute reverse hash values on reversed string
        for (int i = 0; i < primes; i++) {
            ll mod = hashPrimes[i];
            reverseHashValues[i].resize(n);
            for (int j = 0; j < n; j++) {
                // character from the end
                ll v = ((s[n - 1 - j] - 'a' + 1LL) * powersOfBase[i][j]) % mod;
                reverseHashValues[i][j] = (v + (j > 0 ? reverseHashValues[i][j - 1] : 0LL)) % mod;
            }
        }
    }

    // hash of s[l..r] in forward direction
    vector<ll> substringHash(int l, int r) {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++) {
            ll mod = hashPrimes[i];
            ll val1 = hashValues[i][r];
            ll val2 = (l > 0 ? hashValues[i][l - 1] : 0LL);
            ll sub = mod_sub(val1, val2, mod);
            hash[i] = mod_mul(sub, inversePowersOfBase[i][l], mod);
        }
        return hash;
    }

    // hash of s[l..r] in reverse direction (i.e., as if substring is reversed)
    vector<ll> substringReverseHash(int l, int r) {
        vector<ll> hash(primes);
        // map [l..r] in original to [n-1-r .. n-1-l] in reversed-array
        int rl = n - 1 - r;
        int rr = n - 1 - l;
        for (int i = 0; i < primes; i++) {
            ll mod = hashPrimes[i];
            ll val1 = reverseHashValues[i][rr];
            ll val2 = (rl > 0 ? reverseHashValues[i][rl - 1] : 0LL);
            ll sub = mod_sub(val1, val2, mod);
            hash[i] = mod_mul(sub, inversePowersOfBase[i][rl], mod);
        }
        return hash;
    }
};
