#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1010;
int pre[MAXN];

int find(int x) {
	return x == pre[x] ? x : find(pre[x]);
}

void join(int a, int b) {
	int x = find(a);
	int y = find(b);
	pre[x] = y;
}

int main () {
	int t;
	scanf("%d", &t);
	while(t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) pre[i] = i;
		for(int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			join(a, b);
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) 
			if(pre[i] == i) 
				ans++; 
		printf("%d\n", ans);
	} 
	return 0;
}



//ÎÞÑ¹Ëõ 
int find(int x) {
	return pre[x] == x ? x : find(pre[x]);
}


//Â·¾¶Ñ¹Ëõ 
int find(int x) {
	int r = x;
	while(r != pre[r]) {	
		r = pre[r];
	}
	int i = x, j;
	while(pre[i] != r) {
		j = i;
		i = pre[i];
		pre[j] = r;
	} 
	return r;
} 


//µÝ¹éÂ·¾¶Ñ¹Ëõ 
int find(int x) {
	return pre[x] == x ? x : pre[x] =  find(pre[x]);
}
