/*

WC学长面前有一排饭团，每个饭团大小不一，因为他有强迫症，所以他想要从左往右按顺序一个接一个地吃（可以选择吃或不吃），而且每次吃的饭团必须不小于上一次吃的饭团，但是另一方面WC学长又非常贪吃，他想要尽吃可能多的饭团（他觉得数量比质量更重要），他想知道他最多能吃几个饭团，你能帮帮他吗？

Input
本题有多组数据。 
第一行数字n表示有n个饭团（n<=1000） 
第二行有n个数字a1~an（0=<ai<=10000），ai表示从左往右数第i个饭团的体积
Output
最多可以吃到的饭团数。
Sample Input
10
10 9 8 7 6 5 4 3 4 5
Sample Output
3
Hint
无
*/
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int maxn = 1010;
int a[maxn];
int dp[maxn];

int main () {
	int n;
	while(cin >> n) {
		for(int i = 1; i <= n; i++) 
			cin >> a[i], dp[i] = 1;
		for(int i = 2; i <= n; i++) {
			for(int j = 1; j < i; j++) {
				if(a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j]+1);
				} 
			}
		}
		int ans = 1;
		for(int i = 1; i <= n; i++) {
			if(ans < dp[i])
				ans = dp[i];
		}
		cout << ans << endl;
	}
	return 0;
}
