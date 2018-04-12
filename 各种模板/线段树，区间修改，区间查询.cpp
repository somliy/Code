#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

using namespace std;  

typedef long long ll;  
const int maxn = 100000 + 10;  
ll sum[maxn<<2];  
ll make[maxn<<2];  

void pushUP(int rt) {  
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void pushDown(int rt, int len) {  //延迟标记向下更新 
    if(make[rt]) {
        make[rt<<1] += make[rt];
        make[rt<<1|1] += make[rt];
        sum[rt<<1] += make[rt]*(len-(len>>1));
        sum[rt<<1|1] += make[rt]*(len>>1);
        make[rt] = 0;
    }
}

void build(int l, int r, int rt) {  
    if(l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (r+l)>>1;
    build(lson);
    build(rson);
    pushUP(rt);
}

void updata(int L, int R, ll c, int l, int r, int rt) {  
    if(L<=l && r<=R) {
        make[rt] += c;
        sum[rt] += c*(r-l+1);
        return; 
    }
    pushDown(rt, r-l+1);
    int m = (r+l)>>1;
    if(m >= L) updata(L, R, c, lson);
    if(m < R) updata(L, R, c, rson);
    pushUP(rt); 
}

ll query(int L, int R, int l, int r, int rt) {  
    if(l>=L && R>=r) {
        return sum[rt];
    }
    pushDown(rt, r-l+1);
    int m = (r+l)>>1;
    ll ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    memset(sum, 0, sizeof(sum));
    memset(make, 0, sizeof(make));
    build(1, n, 1);
    for(int i = 0; i < q; i++) {
        char op;
        int a, b;
        ll c;
        cin >> op;
        if(op == 'C') {
            scanf("%d %d %lld", &a, &b, &c);
            updata(a, b, c, 1, n, 1);
        }else {
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(a, b, 1, n, 1));
        }
    }
    return 0;
}

/*
	树状数组 
*/ 
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

typedef long long ll;
const int MAX = 100000 + 10;  
ll n, q;  
ll sum[MAX], c1[MAX], c2[MAX];

ll lowbit(ll x) {  
    return x&(-x);
}

void Update(ll x, ll d, ll *c) {  
    while(x <= n) {
        c[x] += d;
        x += lowbit(x);
    }
}

ll Query(ll x, ll *c){  
    ll sum = 0;
    while(x > 0) {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main(){  
    char op[3];
    ll x, y, d;
    while(~scanf("%lld %lld", &n, &q)) {
        memset(c1, 0, sizeof c1);
        memset(c2, 0, sizeof c2);
        for(int i = 1; i <= n; i++) {
        	scanf("%lld", sum+i);
			sum[i] += sum[i-1];
		}
        for(int i = 0; i < q; i++) {
            scanf("%s", op);
            if(op[0] == 'C'){//ans[x]+=d,ans[y+1]-=d
                scanf("%lld %lld %lld", &x, &y, &d);
                Update(x, d, c1);
                Update(y+1, -d, c1);
                Update(x, x*d, c2);
                Update(y+1, -(y+1)*d, c2);
            }else{
                scanf("%lld %lld", &x, &y);
                printf("%lld\n",sum[y]-sum[x-1]+Query(y,c1)*(y+1)-Query(x-1,c1)*x-Query(y,c2)+Query(x-1,c2));
            }
        }
    }
    return 0;
}
