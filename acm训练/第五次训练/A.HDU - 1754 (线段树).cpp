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
