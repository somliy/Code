#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
const int maxn = 1000+10;

int main() {
	int T;
	int a[maxn];
	cin >> T;
	for(int t=1; t<=T; t++) {
		int n,k;
		ll ans = 0; 
		cin >> n >> k;
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		for(int i=0; i<n-k+1; i++) {
			ans += (a[i+k-1] - a[i]);
		} 
		printf("Case #%d: ",t);
		cout << ans << endl;
	}
	
	
	return 0;

} 
