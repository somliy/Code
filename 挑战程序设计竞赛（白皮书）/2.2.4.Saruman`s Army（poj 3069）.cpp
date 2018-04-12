/*


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
const int MAXN = 9999999;
const int maxn = 1010;
const int inf = 0x3f3f3f3f;

int a[maxn];
int n, r;

int solve() {
	sort(a, a+n);
	int i = 0, ans = 0;
	while(i < n) {
		int s = a[i++];
		while(i < n && a[i] - r <= s) i++;
		int p = a[i-1];
		while(i < n && a[i] - r <= p) i++; 
		ans++;
	}
	return ans;
}


int main() {
	while(~scanf("%d %d", &r, &n)) {
		if(n == -1 && r == -1) break;
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		cout << solve() << endl;
	} 
} 
