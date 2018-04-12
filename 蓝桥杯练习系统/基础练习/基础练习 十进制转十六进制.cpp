#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

const int MAXN = 10000;
char str[MAXN];
char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main() {
    long long n, k = 0;
    scanf("%lld", &n);
    if(n == 0) printf("0\n");
    else {
        while(n) {
            str[k++] = a[n % 16];
            n /= 16;
        }
        for(int i = k-1; i >=0; i--)
            printf("%c",str[i]);
    }
    return 0;
}
