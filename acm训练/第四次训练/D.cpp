/*

1284 2 3 5 7的倍数  
基准时间限制：1 秒 空间限制：131072 KB 分值: 5 难度：1级算法题 收藏  关注
给出一个数N，求1至N中，有多少个数不是2 3 5 7的倍数。 例如N = 10，只有1不是2 3 5 7的倍数。
Input
输入1个数N(1 <= N <= 10^18)。
Output
输出不是2 3 5 7的倍数的数共有多少。
Input示例
10
Output示例
1
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
	ll n;
	cin >> n;
	ll a = n/2;
	ll b = n/3;
	ll c = n/5;
	ll d = n/7;
	
	ll ab = n/6;
	ll ac = n/10;
	ll ad = n/14;
	ll bc = n/15;
	ll bd = n/21;
	ll cd = n/35;
	
	ll abc = n/30;
	ll abd = n/42;
	ll acd = n/70;
	ll bcd = n/105;
	
	ll abcd = n/210;
	
	cout << n-(a+b+c+d-ab-ac-ad-bc-bd-cd+abc+abd+acd+bcd-abcd)<< endl;
 	
    return 0; 
} 
