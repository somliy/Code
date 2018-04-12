/*

1008 N的阶乘 mod P
基准时间限制：1 秒 空间限制：131072 KB 分值: 0 难度：基础题 收藏  关注
输入N和P（P为质数），求N! Mod P = ? (Mod 就是求模 %)
例如：n = 10， P = 11，10! = 3628800
3628800 % 11 = 10
Input
两个数N,P，中间用空格隔开。(N < 10000, P < 10^9)
Output
输出N! mod P的结果。
Input示例
10 11
Output示例
10
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<vector> 

using namespace std;

typedef long long ll; 
const int maxn = 100;
const int inf = 0x3f3f3f3f;
const int MAXN = 100000;


int main() {
	int n, p;
	cin >> n >> p;
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
		ans = (ans * i) % p;
	}
	cout << ans << endl;
    return 0; 
} 
