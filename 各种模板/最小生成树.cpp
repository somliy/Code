#include<iostream>
#include<cstring> 
#include<algorithm>

using namespace std;

const int MAXN = 11000;
const int inf = 0x3f3f3f3f;
int n, m;
int pre[MAXN];

struct node {
	int x, y, cost;
	bool operator < (const node& rhs) const {  
        return cost < rhs.cost;  
    } 
}cnt[5050];

int find(int x) {
	return x == pre[x] ? x : find(pre[x]);//return pre[x] == x ? x : pre[x] =  find(pre[x]); 
}

int kruskal() {
	int ans = 0;
	for(int i = 1; i <= n; i++) pre[i] = i;
	sort(cnt+1, cnt+1+m);
	for(int i = 1; i <= m; i++) {
		int x = find(cnt[i].x);
		int y = find(cnt[i].y);
		if(x != y) {
			ans += cnt[i].cost;
			pre[y] = x;
		}
	}
	return ans;
}

int main() {
	while(~scanf("%d", &n) && n) {
		scanf("%d", &m);
		for(int i = 1; i <= m; i++) {
			scanf("%d %d %d", &cnt[i].x, &cnt[i].y, &cnt[i].cost);
		}
		printf("%d\n", kruskal());
	}
	return 0;
}
