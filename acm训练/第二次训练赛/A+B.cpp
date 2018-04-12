/*
A+B
 1000 ms       65536 KiB
Accepted/Submissions: 16/26 (61.54%)
   
Description
给出一个整数n。

定义A为1~n中相邻数字加和的乘积。
定义B为1~n中相邻数字乘积的加和。

求A+B。

Input
先输入一个整数T表示组数。
每组输入一个整数n(0 < n <= 10)。

Output
对于每组输入，输出一个正整数，表示结果。
保证输入输出均在int范围内

Sample
Input

2
1
3
Output

2
23
Hint
对于第二组，A = (1+2)*(2+3),B = 1*2+2*3；

Source
“师创杯”山东理工大学第八届ACM程序设计竞赛 热身赛
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long ll;
const ll MAXN = 100005;

ll solve(ll n) {
	int flag = 0;
	if(n == 0 || n == 1) return 0;
	if(n & 1) {
		n = n+1;
		flag = 1;
	}
	ll m = n/2;
	ll ans1 = ((1+n-1)*m)/2;
	ll ans2 = ((2+n)*m)/2;
	if(flag) ans2 -= n;
	return ans1*ans2;
}

int main() {
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}

