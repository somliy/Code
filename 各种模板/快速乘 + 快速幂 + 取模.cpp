//快速乘法 
int qmul_num(int a, int b) {
    int ans = 0;
    while(b) {
        if(b & 1) ans += a;
        b >>= 1;
		a <<= 1;
    }
    return ans;
}

//快速乘法取模 
int qmul_mod(int a, int b, int mod) {
    int ans = 0;
    while(b) {
        if((b %= mod) & 1) ans += a %= mod;
        b >>= 1;
		a <<= 1;
    }
    return ans % mod;
}

//快速幂 a^n 
int pow_num(int a, int n) {
    if(a == 0) return 0;
    int ans = 1;
    while(n) {
        if(n & 1) ans *= a;
        n >>= 1;
		a *= a;
    }
    return ans;
}

int pow_mod(int a, int n, int mod) {
    if(!a) return 0;
    int ans = 1;
    while(n) {
        if(n & 1) ans = (ans%mod) * (a%mod);
        n >>= 1;
		a *= a %= mod;
    }
    return ans % mod;
}

int pow_mod(int a, int n, int mod) {
    if(!a) return 0;
    int ans = 1;
    while(n) {
        if(n & 1) ans *= a %= mod;
        n >>= 1;
		a *= a;
    }
    return ans % mod;
}
