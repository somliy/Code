#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

struct node { 
    int x, s;
	node (int _s, int _x) {
		s = _s;
		x = _x;
	}  
    bool operator < (const node &a) const {  
        return s > a.s;
    }  
}; 

const int maxn = 760;
int a[maxn], b[maxn], n;

void mergeArray() {
	priority_queue<node> q;
	for(int i = 1; i <= n; i++) {
		q.push(node(a[i]+b[1], 1));
	}
	for(int i = 1; i <= n; i++) {
		node top = q.top();q.pop();
		a[i] = top.s;
		int dex = top.x;
		if(dex+1 <= n) {
			q.push(node(top.s-b[dex]+b[dex+1], dex+1));
		}
	}
}

int main () {
	while(~scanf("%d", &n)) {
		memset(a, 0, sizeof a);
		for(int i = 1; i <= n; i++) 
			scanf("%d", &a[i]);
		for(int i = 1; i < n; i++) {
			for(int j = 1; j <= n; j++) {
				scanf("%d", &b[j]);
			} 
			sort(b+1, b+1+n);
			mergeArray();
		}
		for(int i = 1; i <= n; i++) 
			printf("%d%c", a[i], i == n ? '\n':' ');
	}
	return 0;
} 
