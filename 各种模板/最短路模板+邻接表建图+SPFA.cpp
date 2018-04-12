#include<iostream>  
#include<queue>  
#include<vector>  
#include<cstdio>  

using namespace std;  

const int maxn = 100005;   
const int inf = 1<<29;

struct edge{int to, cost;};  
int dis[maxn], vis[maxn];  

int n, m, s;  
vector<edge> G[maxn];  

void SPFA() {  
    fill(dis, dis+maxn, inf);
	dis[s] = 0;  
    fill(vis, vis+maxn, 0);  
    queue<int> q;  
    q.push(s);  
    while(!q.empty()) {  
        int u = q.front();  
        q.pop();  
        vis[u] = 0;  
        for(int i = 0; i < G[u].size(); i++) {  
            int v=G[u][i].to, len=G[u][i].cost;  
            if(dis[v] > dis[u] + len) {  
                dis[v] = dis[u] + len;  
                if(vis[v] == 0) {  
                    vis[v] = 1;  
                    q.push(v);  
                }  
            }  
        }  
    }  
}  
int main() {  
    while(~scanf("%d %d", &n, &m), (n+m)) {   
        for(int i = 0; i <= n; i++) G[i].clear();  
        for(int i = 0; i < m; i++) {  
            int a, b, w;  
            edge t, rt;  
            scanf("%d %d %d", &a, &b, &w);  
            t.to=b; t.cost=w;  
//            rt.to=a; rt.cost=w;  //Ë«Ïò 
            G[a].push_back(t);  
//            G[b].push_back(rt);  
        }  
        s = 1;  
        SFPA();  
        cout << dis[n] << endl;  
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
