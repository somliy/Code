#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>

using namespace std;

const int MAXN = 105;
int a[105];

struct node {
    int x;
	node (int _x) {
		x = _x;
	}
    bool operator < (const node &a) const {
        return x > a.x;
    }
};

priority_queue<node> q;

int main() {
    int n, x, sum = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &x);
        q.push(node(x));
    }
    while(q.size() > 1) {
        node top1 = q.top();q.pop();
        node top2 = q.top();q.pop();
        sum += top1.x + top2.x;
        q.push(node(top1.x + top2.x));
    }
    printf("%d\n", sum);
    return 0;
}

