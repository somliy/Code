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
int n; 
char s[MAXN];

void solve() {
	int a = 0, b = n-1;
	while(a <= b) {
		bool left = false;
		for(int i = 0; a+i <= b; i++) {
			if(s[a+i] < s[b-i]) {
				left = true;
				break;
			} else if(s[a+i] > s[b-i]) {
				left = false;
				break;
			}
		}
		if(left) putchar(s[a++]);
		else putchar(s[b--]);
	}
	putchar('\n');
}

int main() {
	cin >> n;
	char c;
	getchar();
	for(int i = 0; i < n; i++) 
		scanf("%c%c", &s[i], &c);
	solve();
    return 0;
} 
