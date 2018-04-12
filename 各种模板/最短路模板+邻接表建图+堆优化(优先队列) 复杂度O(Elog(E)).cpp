#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 0x3f3f3f3f 

using namespace std;

const int MAXN = 1010;
int map[MAXN][MAXN],path[MAXN][MAXN];
int n, m;
void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) map[i][j] = 0;
			else map[i][j] = map[j][i] = inf;
		}
	}
}
void floyd() {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					path[i][j] = path[i][k];  
				} 	
			}
 		}
	}
}
int main () {
	while(~scanf("%d %d", &n, &m) && n+m) {
		init();
		int x, y, w;
		for(int i = 1; i <= m; i++) {
			scanf("%d %d %d", &x, &y, &w);
			map[x][y] = map[y][x] = min(w, map[x][y]);
		}
		floyd(1);
		while(scanf("%d %d", &u, &v)) {//输入起点和终点  
            int tmp = u;  
			printf("%d", u);  
			while(tmp != v) {//打印路径  
				printf("-->%d", path[tmp][v]);  
				tmp = path[tmp][v];  
			}  
			//输出最小花费  
			cout << endl;  
			cout << map[u][v] << endl;  
	}
	return 0;
} 
















#include<iostream>
#include<algorithm>
#include<cstring>
 
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAXN = 1010;
int dis[MAXN], vis[MAXN], Map[MAXN][MAXN];
int n, m;

void init() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) Map[i][j] = 0;
			else Map[i][j] = inf;
		}
	}
}

void dijkstra(int st) {
	for(int i = 1; i <= n; i++) 
		dis[i] = Map[st][i];
	memset(vis, 0, sizeof(vis));
	dis[st] = 0; vis[st] = 1;
	for(int cnt = 1; cnt <= n-1; cnt++) {
		int minn = inf, u;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && dis[i] < minn) {
				minn = dis[i];
				u = i;
			}
		}
		if(minn == inf) break;
		vis[u] = 1;
		for(int i = 1; i <= n; i++) {
			if(!vis[i] && dis[i] > dis[u] + Map[u][i]) {
				dis[i] = dis[u] + Map[u][i];
			}
		}
	} 
}

int main () {
	while(~scanf("%d %d", &n, &m) && n) {
		init();
		int x, y, w;
		for(int i = 1; i <= m; i++) {
			scanf("%d %d %d", &x, &y, &w);
			Map[x][y] = Map[y][x] = min(w, Map[x][y]);
		}
		dijkstra(1);
		printf("%d\n", dis[n]);
	}
	return 0;
} 























#include<iostream>  
#include<queue>  
#include<vector>  
#include<cstdio>  

using namespace std;  

const int maxn = 100005;   
const int inf = 0x3f3f3f3f;
int dis[maxn], n;  

typedef struct node {  
    int p, w;  
    node(int a, int b) { p=a; w=b;}  
    friend bool operator < (node a, node b) {
        if(a.w != b.w) return a.w > b.w;  
        return a.p > b.p;  
    }  
  
};  
vector <node> eg[maxn];

void Dijkstra(int st) {  
    for(int i = 0; i <= n; i++) dis[i] = inf;
    dis[st] = 0;  
    priority_queue <node> Q;  
    Q.push(node(st, dis[st]));
    while(!Q.empty()) {  
        node f=Q.top(); Q.pop();  
        for(int i = 0; i < eg[f.p].size(); i++){  
            node t=eg[f.p][i];  
            if(dis[t.p] > t.w + f.w){
                dis[t.p]=t.w+f.w;  
                Q.push(node(t.p, dis[t.p]));  
            }  
        }  
    }  
}  

int main() {  
    int a, b, m, w;  
    while(~scanf("%d %d", &n, &m) && n) {  
        for(int i = 0; i <= n; i++) eg[i].clear();  
        while(m--) {  
            scanf("%d %d %d", &a, &b, &w);  
            eg[a].push_back(node(b,w));  
            eg[b].push_back(node(a,w));  
        }  
        Dijkstra(1);  
        printf("%d\n",dis[n]);  
    }  
    return 0;  
}  
//const inline int read() {
//	int k=0,f=1;  char c=getchar();
//	for(;!isdigit(c);c=getchar())
//	   if(c=='-')   f=-1;
//	for(;isdigit(c);c=getchar())
//	   k=k*10+c-'0';
//	return k*f;
//}
