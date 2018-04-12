#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

typedef unsigned long long ll;
const ll MAXN = 10000;
char str[10000];
int ans[10000];
ll a, b;

int change(char c) {
    if(c >= '0' && c <= '9') return c - '0';
    else if(c >= 'a' && c <= 'f') return (c - 'a' + 10);
    else if(c >= 'A' && c <= 'F') return (c - 'A' + 10);
    return 0;
}

int main() {
    a = 16;
    b = 10;
    ll kase, flag, result;
    kase = 0, flag = 0, result = 0;
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++)
        result += pow(a, len-i-1) * change(str[i]);
    cout << result << endl;
    return 0;
}

