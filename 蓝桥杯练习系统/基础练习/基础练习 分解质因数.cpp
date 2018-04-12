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
const int maxn = 100;
const int inf = 0x3f3f3f3f;
const int MAXN = 100000;
int a[MAXN];
int ca = 0;

void solve(int n) {
	ca = 0;
	printf("%d=", n);
	for(int i = 2; i <= 10000; i++) {
		while(n%i == 0) {
			a[ca++] = i;
			n /= i;
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = n; i <= m; i++) {
		solve(i);
		for(int i = 0; i < ca-1; i++) 
			printf("%d*", a[i]);
		printf("%d\n", a[ca-1]);
	}
    return 0; 
} 
