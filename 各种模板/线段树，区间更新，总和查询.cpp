/* 
	不需要初始化赋值 
	updata多了一个判断 
	pushdown等都没有+= 
	没有查询 
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
#define lson l, mid, rt<<1
#define rson mid+1, r, rt<<1|1

using namespace std;  

int const MAX = 50005;  
int sum[MAX << 2], lazy[MAX << 2];  
int n, q;

struct node  {
    int l, r, c;
}data[MAX*10];

bool cmp(node a, node b) {
    return a.c < b.c;
}

void PushUp(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int ln, int rn, int rt) {
    if(lazy[rt]) {//或+= 
        sum[rt<<1] = lazy[rt]*ln;
        sum[rt<<1|1] = lazy[rt]*rn;
        lazy[rt<<1] = lazy[rt];
        lazy[rt<<1|1] = lazy[rt];
        lazy[rt] = 0;
    }
    return;
}

void Build() {
    memset(sum, 0, sizeof(sum));
    memset(lazy, 0, sizeof(lazy));
}

void Update(int L, int R, int c, int l, int r, int rt) {
	//多了一个判断 
    if(L <= l && r <= R) { 
        if(sum[rt] < c*(r-l+1)) {
            sum[rt] = c*(r-l+1);
            lazy[rt] = c;
        }
        return;
    }
    int mid = (l+r)>>1;
    PushDown(mid-l+1, r-mid, rt);
    if(L <= mid) Update(L, R, c, lson);
    if(mid < R) Update(L, R, c, rson);
    PushUp(rt);
}

int main() {
    while(~scanf("%d %d", &n, &q)) {
        Build();
        for(int i = 0; i < q; i++)
            scanf("%d %d %d", &data[i].l, &data[i].r, &data[i].c);
        sort(data, data + q, cmp);
        for(int i = 0; i < q; i++)
            Update(data[i].l + 1, data[i].r, data[i].c, 1, n, 1);
        printf("%d\n", sum[1]);
    }
}
