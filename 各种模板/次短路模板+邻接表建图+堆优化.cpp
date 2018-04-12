#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

const int MAXN = 55;
const int inf = 1<<30;

struct Edge {
    int v, w;
}; 

vector<Edge> vet[MAXN];

struct Node{
    int v, dist;
    int mark;//��ǣ�1Ϊ���·��2Ϊ�ζ�·��
    bool operator < (const Node &p) const {
        if(p.dist != dist)
            return p.dist < dist;
 
        return p.v < v;//��������������Ĵ�С���򣬾�wa�ˡ�
    }
};
int n, m, s, e;
int dist[MAXN][3];
int dp[MAXN][3];
bool visited[MAXN][3];
//dp[i][1]��ʾ�����i��̵�·�ж�������dp[i][2]��ʾ�ζ̵����� 
//dist[i][1]��ʾ�����i���·�ĳ���,dist[i][2]��ʾ�ζ�·�ĳ���
/*
��vȥ�ɳ�uʱ��������� (�赱ǰdist[v][cas])
���1��dist[v][cas]+w(v,u)<dist[u][1]���ҵ�һ�����̵ľ��룬���ԭ����̵ľ�����Ϊ�ζ̵ľ��룬ͬʱ������̵�.��
dist[u][2]=dist[u][1]  
dist[u][1]=dist[v][cas]+w(v,u);  
dp[u][2]=dp[u][1]  
dp[u][1]=dp[v][cas]��
��Node(dist[u][1],u,1)��Node(dist[u][2],u,2)�������
���2��dist[v][cas]+w(v,u)==dist[u][1]���ҵ�һ���µ���ͬ��������·����dp[u][1]+=dp[v][cas],�������ø���,Ҳ�����
���3��dist[v][cas]+w(v,u)<dist[u][2]�������Ը�����̾��룬�����Ը��´ζ̵ģ������dist[u][2]��dp[u][2] 
dist[u][2]=dist[v][cas]+w(v,u); 
dp[u][2]=dp[v][cas];
��Node(dist[u][2],u,2)�������
���4��dist[v][cas]+w(v,u)==dist[u][2] �ҵ�һ���µ���ͬ����Ĵζ�·,��dp[u][2]+=dp[v][cas],���������¡�
*/
 
 
 
void Dijkstra(int start, int end) {
    for(int i = 0; i < n; i++) {
        dist[i][1] = dist[i][2] = inf;
    }
    memset(dp, 0, sizeof(dp));
    memset(visited, false, sizeof(visited));
    priority_queue<Node> Q;
    Node p, q;
    dist[start][1] = 0;
    dp[start][1] = 1;
    p.dist=0, p.mark=1, p.v=start;
    Q.push(p);
    while(!Q.empty()) {
        p = Q.top();
        Q.pop();
        if(visited[p.v][p.mark]) continue;
        //if(dist[p.v][p.mark]!=p.dist)continue;
        visited[p.v][p.mark] = true;
        for(int i = 0; i < vet[p.v].size(); i++) {
            int v = vet[p.v][i].v;
            int w = vet[p.v][i].w;
            if(!visited[v][1] && p.dist+w<dist[v][1]) {
                //����Ϊ�ζ�·
                if(dist[v][1] != inf) {
                    q.v=v, q.dist=dist[v][1], q.mark=2;
                    dist[v][2] = dist[v][1];
                    dp[v][2] = dp[v][1];
                    Q.push(q);
                }
                dist[v][1] = p.dist+w;
                dp[v][1] = dp[p.v][p.mark];
                q.v=v, q.dist=dist[v][1], q.mark=1;
                Q.push(q);
            }else if(!visited[v][1] && p.dist+w==dist[v][1]) {
                dp[v][1] += dp[p.v][p.mark];
            }else if(!visited[v][2] && p.dist+w<dist[v][2]) {
                dist[v][2] = p.dist+w;
                dp[v][2] = dp[p.v][p.mark];
                q.dist=dist[v][2], q.v=v, q.mark=2;
                Q.push(q);
            }else if(!visited[v][2] && p.dist+w==dist[v][2]) {
                dp[v][2] += dp[p.v][p.mark];
            }
        }
    }
}
 
int main() {
    while(~scanf("%d %d %d %d", &n, &m, &s, &e)) {
        for(int i = 0; i < n; i++) vet[i].clear();
        for(int i = 1; i <=m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            Edge p;
            p.v=v, p.w=w;
            vet[u].push_back(p);
        }
        Dijkstra(s,e);
        printf("%d %d\n",dist[e][2], dp[e][2]);
    }
    return 0;
}
