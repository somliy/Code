/*
A*B
 1000 ms       65536 KiB
Accepted/Submissions: 22/55 (40.00%)
   
Description
一天小白如往常一样约小黑粗去玩。他们两人划着木船在海上荡阿荡。
小白突然跟小黑说“小黑，我来烤烤你"
黑"纳尼"
白"不不不，我来考考你。我这有一个整数n，你能求出1~n中奇数加和与偶数加和的乘积么？"
黑"恩……"
噗通。。。由于小黑迟迟没有得到答案，小白睡了过去，因受力不平衡。友谊的小船居然(终于)翻了……
如果再给小黑一次机会，小黑会……来求助你。如果可以的话，你能帮帮他么?

Input
多组输入。
先输入一个整数T表示组数，保证不超过100000组。
每组一个整数n(0 < n <= 10000)。

Output
对于每组输入，输出一个正整数表示答案。

Sample
Input

3
1
2
3
Output

0
2
8
Hint
输出较大，请用long long类型
%lld输出
 

Source
“师创杯”山东理工大学第八届ACM程序设计竞赛
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;

ll a(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll ans = 1;
	for(ll i = 2; i <= n; i ++) {
		ans *= (i-1+i);
	}
	return ans;
}

ll b(ll n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll ans = 0;
	for(ll i = 2; i <= n; i ++) {
		ans += (i-1)*(i);
	}
	return ans;
}

int main() {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << a(n)+b(n) << endl;
	}
	return 0;
}
