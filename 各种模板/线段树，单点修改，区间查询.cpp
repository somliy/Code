#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;  

const int treen = 200000 + 10;  
int tree[treen << 2];

void pushUP(int rt) {  
    tree[rt] = max(tree[rt<<1], tree[rt<<1|1]);
}

void build(int l, int r, int rt) {  
    if(l == r) {
        scanf("%d", &tree[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void updata(int p, int add, int l, int r, int rt) {  
    if(l == r) {
        tree[rt] = add;//如果是在基础上加的话用+= 
        return;
    }
    int m = (l+r)>>1;
    if(p <= m) updata(p, add, lson);
    else updata(p, add, rson);
    pushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {  
    if(L<=l && r<=R) {
        return tree[rt];
    }
    int m = (r+l)>>1;
    int ret = 0;
    if(L <= m) ret = max(query(L, R, lson), ret);
    if(R > m) ret = max(query(L, R, rson), ret);
    return ret;
}

int main() {  
    int n, m;
    while(~scanf("%d %d", &n, &m)) {
        memset(tree, 0, sizeof(tree));
        build(1, n, 1);
        for(int i = 0; i < m; i++) {
            char op;
            int a, b;
            cin >> op >> a >> b;
            if(op == 'U') {
                updata(a, b, 1, n, 1);
            }else {
                printf("%d\n", query(a, b, 1, n, 1));
            }
        }
    }
    return 0;
}

/*
	树状数组 

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;  

typedef long long ll;  
const int  maxn = 200000 + 100;;  
int h[maxn], a[maxn];  
int n, m;  

inline int lowbit(int x) {  
    return x&(-x);
}
inline void updata(int x) {  
    while(x <= n) {
        h[x] = a[x];
        for(int i = 1; i < lowbit(x); i<<=1)
            h[x] = max(h[x], h[x-i]);
        x += lowbit(x);
    }
}
int findans(int begin, int end) {
    int ans = 0;
    while(end >= begin) {
        ans = max(ans, a[end]);
        end--;
        for(; end-lowbit(end)>=begin; end-=lowbit(end))
        ans = max(ans, h[end]);
    }
    return ans;
}
int main() {  
    while(~scanf("%d %d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            updata(i);
        }
        char ch;
        int x, y;
        for(int i = 0; i < m; i++) {
            cin >> ch >> x >> y;
            if(ch == 'Q') {
                printf("%d\n", findans(x, y));
            }else if(ch == 'U') {
                a[x] = y;
                updata(x);
            }
        }
    }
    return 0;
}
