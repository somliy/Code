#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

const int MAXN = 4096;
int a[MAXN], kase, n;

void factorial(int n) {
    int temp = 0;
    for(int i = 1; i <= MAXN; i++) {
        int x = a[i] * n + temp;
        a[i] = x % 10;
        temp = x / 10;
    }
}


int main() {
    scanf("%d", &n);
    memset(a, 0, sizeof a);
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        factorial(i);
    }
    for(int i = MAXN-1; i >= 1; i--)
        if(a[i] != 0) {
            kase = i;
            break;
        }
    for(int i = kase; i >= 1; i--)
        printf("%d", a[i]);
    printf("\n");
    return 0;
}
