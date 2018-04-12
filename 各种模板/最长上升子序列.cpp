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
