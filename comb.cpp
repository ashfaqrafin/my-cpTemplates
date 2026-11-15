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

