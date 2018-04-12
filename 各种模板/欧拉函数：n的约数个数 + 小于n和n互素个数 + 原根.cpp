/******
*	少于或等于n的数中与n互质的数的数目。 
*
*	求n约数的个数 
*
*	原根= n-1 
*
*	欧拉函数的性质：它在整数n上的值等于对n进行素因子分解后，所有的素数幂上的欧拉函数之积。
*
*	https://www.cnblogs.com/handsomecui/p/4755455.html
*
*	欧拉函数的性质：
*
*		(1)p^k型欧拉函数:
*	
*			若N是质数p(即N=p), φ(n)= φ(p)=p-p^(k-1)=p-1。
*	
*			若N是质数p的k次幂(即N=p^k)，φ(n)=p^k-p^(k-1)=(p-1)p^(k-1)。
*	
*		(2)mn型欧拉函数
*	
*			设n为正整数，以φ(n)表示不超过n且与n互素的正整数的个数，称为n的欧拉函数值。若m,n互质，φ(mn)=(m-1)(n-1)=φ(m)φ(n)。
*	
*		(3)特殊性质:
*	
*			若n为奇数时，φ(2n)=φ(n)。
*		
*			对于任何两个互质 的正整数a,n(n>2)有:a^φ(n)=1 mod n (恒等于)此公式即 欧拉定理
*	
*			当n=p 且 a与素数p互质(即:gcd(a,p)=1)则上式有: a^(p-1)=1 mod n (恒等于)此公式即 费马小定理
*		
*	小于或等于n的数中，与n互质的数的总和为：φ(x) * x / 2  (n>1)。
*/


//单个计算 
typedef long long ll;

ll euler_phi(ll n) {
	ll m = (ll)sqrt(n + 0.5);
	ll ans = n;
	for(ll i = 2; i <= m; i++) if(n % i == 0) {
		ans = ans / i * (i - 1);
		while(n % i == 0) n /= i;
	} 
	if(n > 1) ans = ans / n * (n - 1);
	return ans;
}


//打表 
typedef long long ll;
const ll MAXN = 1000000;
ll phi[MAXN];

void phi_table(ll n, ll* phi) {
	for(ll i = 2; i <= n; i++)  phi[i] = 0;
	phi[1] = 1;
	for(ll i = 2; i <= n; i++) if(!phi[i]) 
	for(ll j = i; j <= n; j += i) {
		if(!phi[j]) phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	}
}

/** 
*	费马小定理
*	
*	假如p是质数，且gcd(a,p)=1
*
*	a^(p-1)=1(mod p)
*
*	f(p) = p - 1;
*
*/






/**
*	同余定理：
*
*    		如果 a mod b = c 则有(a+kb) mod b =c(k为非0整数)
*
*    		如果 a mod b = c 则有(ka) mod b =kc (k为正整数)
*
*    		(a+b) mod c =((a mod c)+(b mod c )) mod c;
*
*    		(a*b) mod c=((a mod c)*(b mod c)) mod c
*
*/








 
