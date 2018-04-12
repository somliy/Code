#include<iostream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

const int maxn = 760;
int n, m;

map<int, vector<int> > 	Map;

int main () {
	while(~scanf("%d %d", &n, &m)) {
		int x;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &x);
			if(!Map.count(x)) Map[x] = vector<int>();
			Map[x].push_back(i);
		}
		for(int i = 1; i <= m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			if(!Map.count(b) || Map[b].size() < a) printf("0\n");
			else printf("%d\n", Map[b][a-1]);
		}
	}
	return 0;
} 
//8 4
//1 3 2 2 4 3 2 1
//1 3
//2 4
//3 2
//4 2
