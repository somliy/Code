/*
小白的追求
 1000 ms       65536 KiB
Accepted/Submissions: 19/72 (26.39%)
   
Description
小白和小黑的小船翻了以后，小白就去追妹子去啦。但是问题随之而来，小白共有10个目标，编号0-9，但是小白只能追求一个，所以小白就去找小金请教如何解决，小金什么都没有说，用手指了一下小白，小白瞬间恍然大悟，“你是让我顺从本心吗？？”，小金说：“我让你哪来的滚哪去，正在写代码，没时间搭理你”。。。。。。，但是问题总要解决，小白决定听天由命，所以小白在小金的模板上偷抄了一个公式为:(n^n)%10,结果是多少就去追求谁

Input
多组输入，每组输入一个整数n（n<=10^9）

Output
输出小白要追求的妹子的编号。

Sample
Input

1
2
3
4
Output

1
4
7
6
Source
“师创杯”山东理工大学第八届ACM程序设计竞赛
*/#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef long long ll;
 
ll pow_mod(ll a, ll n, ll mod) {
    if(!a) return 0;
    ll ans = 1;
    while(n) {
        if(n & 1) ans = (ans%mod) * (a%mod);
        n >>= 1;
		a *= a %= mod;
    }
    return ans % mod;
}

int main() {
	ll n;
	while(~scanf("%lld", &n)) {
		cout << pow_mod(n, n, 10) << endl;
	}
	return 0;
}
