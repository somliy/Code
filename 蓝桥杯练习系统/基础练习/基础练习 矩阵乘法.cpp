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
const int maxn = 100;
const int inf = 0x3f3f3f3f;
int a[maxn][maxn];
int b[maxn][maxn];
int c[maxn][maxn];
int n, m;
void f(int x, int y) {
	for(int i = 1; i <= n; i++) {
		c[x][y] += a[x][i]*b[i][y];
//		printf("c[%d][%d]=a[%d][%d]*b[%d][%d]\n", x, y, x, i, i, y);
	}
//	cout << endl;
}

void solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			f(i, j);
		}
	}
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			a[i][j] = b[i][j] = x;
			c[i][i] = 1; 
		}
	if(m == 0) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cout << c[i][j] << " ";
			}
			cout << endl;
		}
		return 0;
	}
	m--; 
	while(m--) {
		memset(c, 0, sizeof c);
		solve();
		for(int i = 1; i <= n; i++) 
			for(int j = 1; j <=n; j++)
				b[i][j] = c[i][j];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
} 
