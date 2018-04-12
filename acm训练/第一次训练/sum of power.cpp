/*
sum of power
 1000 ms       65536 KiB
Accepted/Submissions: 31/133 (23.31%)
   
Description
Calculate  mod (1000000000+7) for given n，m.

Input
Input contains two integers n,m(1≤n≤1000,0≤m≤10).

Output
Output the answer in a single line.

Sample
Input

10 0
Output

10
Source
“浪潮杯”山东省第八届ACM大学生程序设计竞赛（感谢青岛科技大学）


*/
#include<iostream>
#include<algorithm>
#include<cmath>
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
	ll n, m;
	ll mod = 1000000000+7;
	cin >> n >> m;
	ll ans = 0;
	for(ll i = 1; i <= n; i++) {
		ans += pow_mod(i, m, mod);
		ans %= mod;
	}
	cout << ans << endl;
	return 0; 
} 
