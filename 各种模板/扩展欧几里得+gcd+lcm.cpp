

//最大公约数  辗转相除法 
typedef long long LL; 
const LL MAXN = 1000000; 

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a%b);
}

//如果直接a%b==0,说明a=bx一定成立，这个是从本身开始变小的，换句话说是从除自己开始的，
//往后只会越来越来小（判定的数），那么当成立的时候就说明，a可以被b整除，b可以被b整除，
//b就是最大公约数
//如果不是一次得到a%b==0，那么我们把a中不能被整除的部分拿掉，a%b，因为这部分不管怎么变化，
//始终就是一个不能被整除的部分，与一个数可以用素数的次方积表达一样，
//去掉这一部分，再来比较是否可以被整除，如果可以就如上面所说（要说明的一点是，如果不是一次得到，a，b的值已经不是当初的值了），
//如果可以了，那么b就是要求的值，不是继续往下求余，直到b==0，b一定可以到0，因为所有的数都可以被1整除。 




//扩展欧几里得
typedef long long LL; 
const LL MAXN = 1000000; 
 
LL extgcd(LL a, LL b, LL &x, LL &y) {
	LL d = a;
	if(b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1; y = 0;
	}
	return d;
}

//ax+by=c  http://blog.csdn.net/loi_dqs/article/details/49488851 
//返回c的 倍数，可能与c相同，可能变小，用a/gcd为缩小倍数
//如果 c%gcd != 0 的话， 方乘无解 、
//a的 最终结果为(a*c/gcd)mod(l/gcd) 
//printf("%lld\n", ((x*c/gcd)%(l/gcd)+(l/gcd))%(l/gcd));

//ax+by=1，如果gcd(a,b)!=1，说明两个数不互质，是无解的，当两个数互质的时候， ax+by=1才会成立；
//只要b!=0，一直算下去，直到等于0，x=1，y=0，然后执行 y -= (a / b) * x, 这相当于一个递归，每次ab交换，xy跟着交换，
//最后求答案的时候，逆着过程来一遍，就可以得到答案了，例子如博客 




//最小公倍数 

typedef long long LL;  
const LL MAXN = 1000000;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a%b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
} 




//用扩展欧几里德算法求解模线性方程
typedef long long LL;  
const LL MAXN = 1000000;
LL x0, y0, kx, ky;  

LL exgcd(LL a, LL b, LL &x, LL &y) {  
     if(a==0 && b==0) return -1;  
     if(b == 0) { 
		 x=1; y=0; 
		 return a;  
	 }  
     LL d = exgcd(b, a%b, y, x);  
     y -= a/b*x;  
     return d;  
} 

LL MLE(LL a, LL b, LL mod) {  // 返回(a*x)%mod=b 的最小正整数解   求最小乘法逆元 ans是x 
    LL x, y;  
    LL gcd = exgcd(a, mod, x, y);  
    if(b%gcd != 0) return -1;  //若返回-1，则该方程无解  
    x *= b / gcd;  
    mod /= gcd;  
    if(mod < 0) mod =- mod;  
    LL ans = x % mod;  
    if(ans <= 0) ans += mod;  //其他解为： ans+i*mod （i为整数）  
    return ans;  
}  

bool LE(LL a, LL b, LL c) {   //解线性方程ax+by=c  
    LL x1, y1;  
    LL gcd = exgcd(a, b, x1, y1);  
    if(c%gcd) return false;  //无整数解  
    x0 = x1*c/gcd, y0 = y1*c/gcd;  
    kx = b/gcd, ky = -a/gcd;  
    return true;   //有解，解集为：（x0+kx*t,y0+ky*t） t为整数  
}  

//同余方程 ax≡b (mod n)对于未知数 x 有解，当且仅当 gcd(a,n) | b。且方程有解时，方程有 gcd(a,n) 个解。
//求解方程 ax≡b (mod n) 相当于求解方程 ax+ ny= b, (x, y为整数)
//设 d= gcd(a,n)，假如整数 x 和 y，满足 d= ax+ ny(用扩展欧几里德得出)。如果 d| b，则方程
//a* x0+ n* y0= d， 方程两边乘以 b/ d，(因为 d|b，所以能够整除)，得到 a* x0* b/ d+ n* y0* b/ d= b。
//所以 x= x0* b/ d，y= y0* b/ d 为 ax+ ny= b 的一个解，所以 x= x0* b/ d 为 ax= b (mod n ) 的解。
//ax≡b (mod n)的一个解为 x0= x* (b/ d ) mod n，且方程的 d 个解分别为 xi= (x0+ i* (n/ d ))mod n {i= 0... d-1}。
//设ans=x*(b/d),s=n/d;
//方程ax≡b (mod n)的最小整数解为：(ans%s+s)%s;

