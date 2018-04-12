#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

const int MAXN = 105;
char str1[MAXN], str2[MAXN];
int a[MAXN], b[MAXN], ans[MAXN];

int main() {
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    memset(ans, 0, sizeof ans);
    int temp = 0, kase = 0;
    scanf("%s%s", str1, str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 1, j = len1-1; i <= len1; i++, j--) a[i] = str1[j] - '0';
    for(int i = 1, j = len2-1; i <= len2; i++, j--) b[i] = str2[j] - '0';
    for(int i = 1; i <= max(len1, len2)+1; i++) {
        int x = a[i] + b[i] + temp;
        ans[i] = x % 10;
        temp = x / 10;
    }
    for(int i = MAXN-1; i >= 1; i--)
        if(ans[i] != 0) {
            kase = i;
            break;
        }
    for(int i = kase; i >= 1; i--)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}

