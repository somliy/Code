//中国剩余定理——韩信点兵
//
//因为n%3=2, n%5=3, n%7=2 且 3，5，7互质
//使5 ×7 ×a被 3 除余 1，有35 ×2 = 70，即a = 2； 
//使3 ×7 ×b被 5 除余 1，用21 ×1 = 21，即b = 1； 
//使3 ×5 ×c被 7 除余 1，用15 ×1 = 15，即c = 1。
//mod = 3 ×5 ×7 = 21252；
//n =（70×x+21×y+15×z）% lcm(3,5,7) = 23 这是n的最小解
 
 
//费马小定理
//mod一定为奇数 
//a是其他数组之积（5 ×7），n为此余数-2（3-2），mod为3数乘积
//return 的是需要乘的数，res ×5 ×7 是 输入的系数 
typedef long long ll;  

ll pow_mod(ll a, ll n, ll mod) {
	if(!a) return 0;  
    ll res = 1;  
    while(n > 0) {  
        if(n & 1) res = res * a % mod;  
        a = a * a % mod;  
        n >>= 1;  
    }  
    return res;  
} 

//扩展欧几里得
//ax - by = d 
//ax - my = 1
//返回x 

typedef  long long ll; 
 
void extgcd(ll a, ll b, ll& d, ll& x, ll& y) {  
    if(!b) {
		d = a;
		x = 1;
		y = 0;
	}else {
		extgcd(b, a%b, d, y, x); 
		y -= x * (a / b); 
	}  
}  
ll inverse(ll a, ll n) {  
    ll d, x, y;  
    extgcd(a, n, d, x, y);  
    return d == 1 ? (x + n) % n : -1;  
}  


//逆元线性筛 ( P为质数 )
//求1,2,...,N关于P的逆元（P为质数）
//复杂度：O(N) 

typedef long long ll;

ll inv[N];  
void pre(int MOD) {  
    inv[0] = inv[1]=1;  
    for(int i=2;i<N;i++)
        inv[i]=((MOD-MOD/i)*inv[MOD%i])%MOD;  
}    
int main(){  
    int n,p;
    cin>>n>>p;
    pre(p);
    for(int i=1;i<=n;++i)
        printf("%d\n",inv[i]);
    return 0;  
}  


 
