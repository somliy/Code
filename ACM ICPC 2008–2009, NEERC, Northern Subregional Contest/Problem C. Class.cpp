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
    freopen("class.in","r",stdin);  
    freopen("class.out","w",stdout); 
	int k, n, m, a[105][105];
	cin >> k >> n >> m;
	int minn = (k+1)/2;
	memset(a, 0, sizeof(a));
	for(int i = 1; i<=n&&i<=minn; i++) {
		a[i][1] = 1;
		k--;
	}
	for(int i = 2; i<=m&&i<=minn; i++) {
		a[1][i] = 1;
		k--;
	}
	printf("%d\n", min(min(n, m), minn));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(a[i][j] == 1) {
				printf("#");
			}else {
				if(k) {
					printf("#");
					k--;
				}else {
					printf(".");
				}
			}
		} 
		printf("\n");
	}
	printf("\n");
	return 0;	
}
