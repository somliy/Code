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

const ll inf = 0x3f3f3f3f;
const ll MAXN = 1000005;

ll a[MAXN],b[MAXN]; 

int main() {
	
    freopen("deposits.in","r",stdin);  
    freopen("deposits.out","w",stdout);  
	ll n, m, x, ans = 0;
	cin >> n;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	ll Maxn,Maxm;
	Maxn = Maxm = 0; 
	for(ll i = 1; i <= n; i++) {
		cin >> x;
		Maxn = max(Maxn,x);
		a[x] ++;
	}
	cin >> m;
	for(ll i = 1; i <= m; i++) {
		cin >> x;
		Maxm = max(Maxm,x);
		b[x] ++;
	}
	for(ll i = 1; i <= Maxm; i++) {
		if(b[i]!=0){
			for(ll j=1;j*i<=Maxn;j++){
				if(a[j*i]!=0){
					ans = ans+ b[i] * a[j*i];
				}
			}
		}
	}
	cout << ans << endl;
    return 0; 
} 
