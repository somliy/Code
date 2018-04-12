#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<set>
#include<vector> 

using namespace std;  
  
const int INF = 0x3f3f3f3f; 
const int MAXN = 1000005;
vector <int > G[MAXN];  
vector<int > E[MAXN];  
bool vis[MAXN];  
int d[MAXN];  
  
void init() {  
    memset(vis, 0, sizeof(vis));  
}   
  
void dfs(int u) {  
    vis[u] = 1;  
    int size = G[u].size();
    for(int i = 0; i < size; i++) {
        int v = G[u][i];  
        if(!vis[v]) {  
            d[v] = d[u] + E[u][i];  
            dfs(v);  
        }  
    }  
}  
  
int main() {  
    int n;  
    cin >> n;  
    int u, v, w;  
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d %d", &u, &v, &w);  
        G[u-1].push_back(v-1);
        E[u-1].push_back(w);  
        G[v-1].push_back(u-1);  
        E[v-1].push_back(w);  
    }  
    init();  
    for(int i = 0; i<n; i++)    
		d[i] = (i == 0?0:INF);  
    dfs(0);  
    int start = 0;  
    int max = -1;  
    for(int i = 0; i < n; i++) {  
        if (d[i] > max && d[i] != INF) {  
            max = d[i];  
            start = i;  
        }  
    }   
    init();  
    for(int i = 0; i<n; i++)    
		d[i] = (i == start?0:INF);  
    dfs(start);  
    int ans = -1;  
    for(int i = 0; i < n; i++) {  
        if (d[i] > ans && d[i] != INF) {  
            ans = d[i];  
        }  
    }  
    cout << ans << endl;
    return 0;  
}  
