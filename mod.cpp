/*modular operations*/
int power_mod(int v, int n,int mod)
{
    v %= mod;
    if (v == 0)
        return 0;
    n %= (mod - 1);
    int ret = 1;
    for (; n; n >>= 1, v = (v * v) % mod)
        if (n & 1)
            ret = (ret * v) % mod;
    return ret;
}
int mod_sub(int x, int y,int mod)
{
    x %= mod;
    y %= mod;
    return (x + mod - y) % mod;
}
int mod_add(int x, int y,int mod)
{
    x %= mod;
    y %= mod;
    return (x + y) % mod;
}
int mod_mul(int x, int y,int mod)
{
    x %= mod;
    y %= mod;
    return (x * y) % mod;
}
int mod_inv(int x,int mod)
{
    x %= mod;
    return power_mod(x, mod - 2,mod);
}
int mod_div(int x, int y,int mod)
{
    x %= mod;
    y %= mod;
    return mod_mul(x, mod_inv(y,mod),mod);
}
/*modular operations*/
